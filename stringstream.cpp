string s;
stringstream ss;
int n, i, sum, a;
cin >> n;
getline(cin, s); // 讀取換行
for (i=0; i<n; i++)
{
    getline(cin, s);
    ss.clear();
    ss.str(s);
    sum=0;
    while (1)
    {
        ss >> a;
        if ( ss.fail() ) break;
        sum+=a;
    }
    cout << sum << endl;
}
