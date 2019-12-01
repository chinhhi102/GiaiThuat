#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fora(i,a,b) for(int i=a;i<=b;i++)
#define fors(i,a,b) for(int i=a;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x);
#define scll(x) scanf("%lld",&x);
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;

enum Note {
    A("A"),
    A_sharp("A#"),
    B("B"),
    C("C"),
    C_sharp("C#"),
    D("D"),
    D_sharp("D#"),
    E("E"),
    F("F"),
    F_sharp("F#"),
    G("G"),
    G_sharp("G#");

    String code;

    Note(String code) {
        this.code = code;
    }

    static Note findByCode(String code) {
        for (Note note : values()) {
            if (Objects.equals(code, note.code))
                return note;
        }
        throw new IllegalArgumentException();
    }
};

 static class MajorScale {
    private static final int[] INTERVALS = {2, 2, 1, 2, 2, 2, 1};
    Note dominant;
    Set<Note> notes;

    MajorScale(Note dominant) {
        this.dominant = dominant;

        int i = dominant.ordinal();
        notes = EnumSet.of(dominant);
        for (int interval : INTERVALS) {
            i += interval;
            notes.add(Note.values()[i % Note.values().length]);
        }
        notes = Collections.unmodifiableSet(notes);
    }

    public boolean matches(Collection<Note> melody) {
        return notes.containsAll(melody);
    }
}

int main(){
	vector<char> melody[3];
    int n;sc(n);

//    Set<Note> melody = EnumSet.noneOf(Note.class);
    for (int i = 0; i < n; i++) {
    	char a[3];
    	scanf("%c",&a);
    	melody.pb(a);
//        melody.add(Note.findByCode(sc.next()));
    }
    List<Note> matched = new ArrayList<>();
    for (Note dominant : Note.values()) {
        if (new MajorScale(dominant).matches(melody))
            matched.add(dominant);
    }
    if (matched.isEmpty()) {
        System.out.println("none");
    } else {
        matched.forEach(m -> System.out.print(m.code + " "));
    }
	return 0;
}
