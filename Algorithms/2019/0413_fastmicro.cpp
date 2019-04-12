#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int s, t, a, b;
        cin >> s >> t >> a >> b;
        int result = -1;
        if (b == 1) {
            if ((t - s) % a == 0) result = (t - s) / a;
        }
        else {
            result = 0;
            while (t != s) {
                result++;
                if (t % b == 0) {
                    if (t / b < s) t -= a;
                    else t /= b;
                }
                else t -= a;
  
                if (t < s) {
                    result = -1;
                    break;
                }
            }
        }
        cout << '#' << i << ' ' << result << endl;
  
    }
    return 0;
}
