#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> ar) {
    int A[6] = {0};
    for (int i = 0; i < ar.size(); ++i) {
        A[ar[i] - 1] += 1;
    }
    int min_index = 0, max = INT_MIN;
    for (int i = 0; i < 5; ++i) {
        if (A[i] > max) {
            max = A[i];
            min_index = i;
        } else if (A[i] == max) {
            min_index = min(min_index, i);
        }
    }
    return min_index + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int ar_count;
    cin >> ar_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = migratoryBirds(ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
