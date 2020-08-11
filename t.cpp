#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

set<LL>all;

class OCCS : public map<LL,LL>
{
public:
    OCCS();
    ~OCCS();
    OCCS operator+(const OCCS &b) const{
        OCCS c;
        const OCCS &a = (*this);
        for(auto &v: a)
            c[v.first] += v.second;
        for(auto &v: b)
            c[v.first] += v.second;
        
        return c;
    }

    OCCS operator+=(const OCCS &b){
        OCCS &a = (*this);
        for(auto &v: b)
            a[v.first] += v.second;
        
        return *this;
    }
};

OCCS::OCCS()
{
    for(auto &v:all)
        (*this)[v] = 0;
}

OCCS::~OCCS()
{
}


int main(int argc, char const *argv[])
{

    return 0;
}
