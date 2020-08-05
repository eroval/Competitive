#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string a1 = "00:00:00";
    if (s[8] == 'P' && s[9] == 'M') {
        int c = (s[0] - '0') * 10 + s[1] - '0';
        if (c != 12) {
            c += 12;
        }
        s[0] = ((c / 10) % 10) + '0';
        s[1] = (c % 10) + '0';
    }
    else {
        int c = (s[0] - '0') * 10 + s[1] - '0';
        if (c == 12) {
            s[0] = '0';
            s[1] = '0';
        }
    }

    for (int i = 0; i < 8; i++) {
        a1[i] = s[i];
    }
    return a1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
