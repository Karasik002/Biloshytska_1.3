#include <stdio.h>
#include <windows.h>

// ������� ��� ���������� ������� ����� �� ������� �������� �
long long countNumbers(int r) {
    if (r == 1) return 2; // "5" � "9"
    if (r == 2) return 4; // "55", "59", "95", "99"

    // dp[i][0] - ������� ����� �������� i, �� ����������� �� ���� �����
    // dp[i][1] - ������� ����� �������� i, �� ����������� �� �� ������� �����
    long long dp[r+1][2];

    dp[1][0] = 2; // "5", "9"
    dp[1][1] = 0;
    dp[2][0] = 2; // "59", "95"
    dp[2][1] = 2; // "55", "99"

    for (int i = 3; i <= r; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1]; // ��������� "5" ��� "9" �� ����� ��� ���� ��������� ���� � ����
        dp[i][1] = dp[i-1][0]; // ��������� ����� ���� � ����� �� ����� ��� ��������� ���� � ����
    }

    return dp[r][0] + dp[r][1];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int r;
    printf("������ ������� ������� �: ");
    scanf("%d", &r);

    if (r <= 0 || r > 30) {
        printf("ʳ������ ������� ������� ���� �� 1 �� 30.\n");
        return 1;
    }

    long long result = countNumbers(r);
    printf("ʳ������ ����� �� %d �������: %lld\n", r, result);

    return 0;
}
