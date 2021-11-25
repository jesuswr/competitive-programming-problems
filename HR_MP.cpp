#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY coordinates as parameter.
 */

long long solve(vector<vector<int>> coordinates) {
    long long n = coordinates.size();
    vector< pair<long long, long long> > x(n), y(n);
    vector< long long > ans(n, 0);
    for (long long i = 0; i < n; ++i) {
        x[i].first = coordinates[i][0] + coordinates[i][1];
        y[i].first = coordinates[i][1] - coordinates[i][0];
        x[i].second = y[i].second = i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long suf_x = 0, pre_x = 0, suf_y = 0, pre_y = 0;
    for (long long i = 0; i < n; ++i) {
        suf_x += x[i].first;
        suf_y += y[i].first;
    }
    for (long long i = 0; i < n; ++i) {
        suf_x -= x[i].first;
        suf_y -= y[i].first;

        ans[x[i].second] += (suf_x - (n - 1ll - i) * x[i].first) + (i * x[i].first - pre_x);
        ans[y[i].second] += (suf_y - (n - 1ll - i) * y[i].first) + (i * y[i].first - pre_y);

        pre_x += x[i].first;
        pre_y += y[i].first;
    }
    long long answer = ans[0] / 2;
    for (long long i = 1; i < n; ++i)
        answer = min(answer, ans[i] / 2);
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> coordinates(n);

    for (int i = 0; i < n; i++) {
        coordinates[i].resize(2);

        string coordinates_row_temp_temp;
        getline(cin, coordinates_row_temp_temp);

        vector<string> coordinates_row_temp = split(rtrim(coordinates_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int coordinates_row_item = stoi(coordinates_row_temp[j]);

            coordinates[i][j] = coordinates_row_item;
        }
    }

    long long result = solve(coordinates);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
