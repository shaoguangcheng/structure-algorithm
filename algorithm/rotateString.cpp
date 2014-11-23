// method1
/*
void rotate_string(string& s, int offset)
{
    int N = s.size();
    offset %= N;
    if(0 == N || offset == 0)
        return;

    char tmp = s[0];
    for(int i = 1; i <= N; ++i){
        tmp ^= s[i*(offset-1)%N];
        s[i*(offset-1)%N] ^= tmp;
        tmp ^= s[i*(offset-1)%N];
    }

    return;
}*/

//method2
void rotate_string(string &s,  int offset)
{
    int N = s.size();
    offset %= N;

    if(0 == N || 0 == offset)
        return;

    char tmp;
    for(int i = 0; i < N/2; ++i){
        tmp = s[i];
        s[i] = s[N-i-1];
        s[N-i-1] = tmp;
    }

    offset = N - offset;
    for(int i = 0; i < offset/2; ++i){
        tmp = s[i];
        s[i] = s[offset-i-1];
        s[offset-i-1] = s[i];
    }

    for(int i = offset; i < (N+offset)/2; ++i){
        tmp = s[i];
        s[i] = s[N-i-1+offset];
        s[N-i-1-offset] = tmp;
    }

}
