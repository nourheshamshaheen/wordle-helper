#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

//Code to solve the daily wordle

vector<string> fiveLetterWords;
//make vectors for each letter
vector<string> a;
vector<string> b;
vector<string> c;
vector<string> d;
vector<string> e;
vector<string> f;
vector<string> g;
vector<string> h;
vector<string> i;
vector<string> j;
vector<string> k;
vector<string> l;
vector<string> m;
vector<string> n;
vector<string> o;
vector<string> p;
vector<string> q;
vector<string> r;
vector<string> s;
vector<string> t;
vector<string> u;
vector<string> v;
vector<string> w;
vector<string> x;
vector<string> y;
vector<string> z;

int counter = 0;
void load_dictionary();
void deleteGrayElements(char letter);
void getYellowElements(char letter, int position);
void getGreenElements(char letter, int position);
void removeDuplicates();

int main()
{
    cout << "*** WELCOME TO WORDLE HELPER ***" << endl;
    int choice = 3;
    //best starter words according to online algorithm "Unwordle" (sauce and slice are repeated since they are scientifically the best starter words)
    vector<string> starters;
    starters.push_back("sauce");
    starters.push_back("slice");
    starters.push_back("shale");
    starters.push_back("saute");
    starters.push_back("sauce");
    starters.push_back("slice");
    starters.push_back("share");
    starters.push_back("sooty");
    starters.push_back("shine");
    starters.push_back("suite");
    starters.push_back("crane");

    // starters counter = 11;

    load_dictionary();

    string word;

    while(choice != 0)
    {
        cout << "Get best starter words according to Unwordle or try your luck with a random word?" << endl;
        cout << "1 - Best starter words \n2- Random Word" << endl;
        cin >> choice;
        if(choice == 2)
        {
            srand(time(0));
            int random = rand()%counter;
            cout << "Here's your starter word!" << endl;
            word = fiveLetterWords[random];
        }
        else if(choice == 1)
        {
            srand(time(0));
            int random = rand()%11;
            cout << "Here's your starter word!" << endl;
            word = starters[random];
        }
        cout << word << endl;
        cout << "Do you want another word?" <<endl;
        cout <<"0 - I'm okay with this word. \n1 - I don't like this word. Another one please!" << endl;
        cin >> choice;
    }
    int win = 0;
    while(fiveLetterWords.size() > 1 && win == 0)
    {
        cout << "Guess done, enter green/yellow/gray for each letter: \n1-Green 2-Yellow 3-Gray" << endl;
        for(int i = 0; i < 5; i++)
        {
        cout << "Letter " << word[i] << endl;
        cin >> choice;
        if(choice == 3)
        {
            deleteGrayElements(word[i]);
        }
        else if(choice == 2)
        {
            getYellowElements(word[i], i);
        }
        else if(choice == 1)
        {
            getGreenElements(word[i], i);
        }
        removeDuplicates();
        cout << "Number of possible words left: ";
        cout << fiveLetterWords.size() << endl;
        }
        cout <<"Do you want to see all possible words or a random word?\n1 - Random Word  2- All words!" << endl;
        cin >> choice;
        if(choice == 1)
        {
            int temp = 2;
            while(temp!= 0)
            {
                int random = rand()%fiveLetterWords.size();
                cout << fiveLetterWords[random] << endl;
                cout << "Do you want another word?" <<endl;
                cout <<"0 - I'm okay with this word. \n1 - I don't like this word. Another one please!" << endl;
                cin >> temp;
            }
        }
        else if(choice == 2)
        {
            for(int i = 0; i < fiveLetterWords.size(); i++)
                cout << fiveLetterWords[i] << endl;
        }
        cout << "Enter chosen word: " << endl;
        cin >> word;
        cout << "Did you win?\n0- Not yet :(   1- YES! Thank you Alaska" << endl;
        cin >> win;
    }
    cout << "Goodbye! Hope I helped!" << endl;
    return 0;

}

void load_dictionary()
{
    counter = 0;
    string temp;
    //   bool repeat;  --> see if u want to eliminate repeated letters
    //open specified file
    // Read from the text file
    ifstream MyDictionary("EN-US-Dictionary.txt");
    cout << "Dictionary loading..." << endl;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyDictionary, temp)) {
        if(temp.length() == 5 && temp[1] != 39 && temp[2] != 39 && temp[3] != 39 && temp[4] != 39)
        {
            temp[0] = tolower(temp[0]);
            fiveLetterWords.push_back(temp);
            counter++;
            //put each word in correct bin
            for(int xx = 0; xx < 5; xx++)
            {
                switch(temp[xx])
                {
                case 'a':
                    a.push_back(temp);
                    break;
                case 'b':
                    b.push_back(temp);
                    break;
                case 'c':
                    c.push_back(temp);
                    break;
                case 'd':
                    d.push_back(temp);
                    break;
                case 'e':
                    e.push_back(temp);
                    break;
                case 'f':
                    f.push_back(temp);
                    break;
                case 'g':
                    g.push_back(temp);
                    break;
                case 'h':
                    h.push_back(temp);
                    break;
                case 'i':
                    i.push_back(temp);
                    break;
                case 'j':
                    j.push_back(temp);
                    break;
                case 'k':
                    k.push_back(temp);
                    break;
                case 'l':
                    l.push_back(temp);
                    break;
                case 'm':
                    m.push_back(temp);
                    break;
                case 'n':
                    n.push_back(temp);
                    break;
                case 'o':
                    o.push_back(temp);
                    break;
                case 'p':
                    p.push_back(temp);
                    break;
                case 'q':
                    q.push_back(temp);
                    break;
                case 'r':
                    r.push_back(temp);
                    break;
                case 's':
                    s.push_back(temp);
                    break;
                case 't':
                    t.push_back(temp);
                    break;
                case 'u':
                    u.push_back(temp);
                    break;
                case 'v':
                    v.push_back(temp);
                    break;
                case 'w':
                    w.push_back(temp);
                    break;
                case 'x':
                    x.push_back(temp);
                    break;
                case 'y':
                    y.push_back(temp);
                    break;
                case 'z':
                    z.push_back(temp);
                    break;
                }
            }
        }
    }
    // Close the file
    MyDictionary.close();
    printf("File loaded successfully. %d five letter words found.\n", counter);
}
//faulty function, leave it here for good luck
/*void deleteGrayElements(char letter)
{
    for(int jj = 0; jj < fiveLetterWords.size(); jj++)
    {
        switch(letter)
        {
        case 'a':
            for(int kk = 0; kk < a.size(); kk++)
            {
                if(a[kk] == fiveLetterWords[jj])
                {
                    a.erase(a.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'b':
            for(int kk = 0; kk < b.size(); kk++)
            {
                if(b[kk] == fiveLetterWords[jj])
                {
                    b.erase(b.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'c':
            for(int kk = 0; kk < c.size(); kk++)
            {
                if(c[kk] == fiveLetterWords[jj])
                {
                    c.erase(c.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'd':
            for(int kk = 0; kk < d.size(); kk++)
            {
                if(d[kk] == fiveLetterWords[jj])
                {
                    d.erase(d.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'e':
            for(int kk = 0; kk < e.size(); kk++)
            {
                if(e[kk] == fiveLetterWords[jj])
                {
                    e.erase(e.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'f':
            for(int kk = 0; kk < f.size(); kk++)
            {
                if(f[kk] == fiveLetterWords[jj])
                {
                    f.erase(f.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'g':
            for(int kk = 0; kk < g.size(); kk++)
            {
                if(g[kk] == fiveLetterWords[jj])
                {
                    g.erase(g.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'h':
            for(int kk = 0; kk < h.size(); kk++)
            {
                if(h[kk] == fiveLetterWords[jj])
                {
                    h.erase(h.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'i':
            for(int kk = 0; kk < i.size(); kk++)
            {
                if(i[kk] == fiveLetterWords[jj])
                {
                    i.erase(i.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'j':
            for(int kk = 0; kk < j.size(); kk++)
            {
                if(j[kk] == fiveLetterWords[jj])
                {
                    j.erase(j.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'k':
            for(int kk = 0; kk < k.size(); kk++)
            {
                if(k[kk] == fiveLetterWords[jj])
                {
                    k.erase(k.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'l':
            for(int kk = 0; kk < l.size(); kk++)
            {
                if(l[kk] == fiveLetterWords[jj])
                {
                    l.erase(l.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'm':
            for(int kk = 0; kk < m.size(); kk++)
            {
                if(m[kk] == fiveLetterWords[jj])
                {
                    m.erase(m.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'n':
            for(int kk = 0; kk < n.size(); kk++)
            {
                if(n[kk] == fiveLetterWords[jj])
                {
                    n.erase(n.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'o':
            for(int kk = 0; kk < o.size(); kk++)
            {
                if(o[kk] == fiveLetterWords[jj])
                {
                    o.erase(o.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'p':
            for(int kk = 0; kk < p.size(); kk++)
            {
                if(p[kk] == fiveLetterWords[jj])
                {
                    p.erase(p.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'q':
            for(int kk = 0; kk < q.size(); kk++)
            {
                if(q[kk] == fiveLetterWords[jj])
                {
                    q.erase(q.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'r':
            for(int kk = 0; kk < r.size(); kk++)
            {
                if(r[kk] == fiveLetterWords[jj])
                {
                    r.erase(r.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 's':
            for(int kk = 0; kk < s.size(); kk++)
            {
                if(s[kk] == fiveLetterWords[jj])
                {
                    s.erase(s.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 't':
            for(int kk = 0; kk < t.size(); kk++)
            {
                if(t[kk] == fiveLetterWords[jj])
                {
                    t.erase(t.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'u':
            for(int kk = 0; kk < u.size(); kk++)
            {
                if(u[kk] == fiveLetterWords[jj])
                {
                    u.erase(u.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'v':
            for(int kk = 0; kk < v.size(); kk++)
            {
                if(v[kk] == fiveLetterWords[jj])
                {
                    v.erase(v.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'w':
            for(int kk = 0; kk < w.size(); kk++)
            {
                if(w[kk] == fiveLetterWords[jj])
                {
                    w.erase(w.begin()+kk);
                    fiveLetterWords.erase(fiveLetterWords.begin()+jj);
                }
            }
            break;
        case 'x':
            for(int kk = 0; kk < x.size(); kk++)
            {
                if(x[kk] == fiveLetterWords[jj])
                        fiveLetterWords.erase(fiveLetterWords.begin()+jj);
            }
            break;
        case 'y':
            for(int kk = 0; kk < y.size(); kk++)
            {
                if(y[kk] == fiveLetterWords[jj])
                        fiveLetterWords.erase(fiveLetterWords.begin()+jj);
            }
            break;
        case 'z':
            for(int kk = 0; kk < z.size(); kk++)
            {
                if(z[kk] == fiveLetterWords[jj])
                        fiveLetterWords.erase(fiveLetterWords.begin()+jj);
            }
            break;
        }
    }
}*/
void deleteGrayElements(char letter)
{
    vector<string> temp;
    for(int jj = 0; jj < fiveLetterWords.size(); jj++)
    {
        switch(letter)
        {
        case 'a':
            for(int kk = 0; kk < a.size(); kk++)
            {
                if(a[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'b':
            for(int kk = 0; kk < b.size(); kk++)
            {
                if(b[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'c':
            for(int kk = 0; kk < c.size(); kk++)
            {
                if(c[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'd':
            for(int kk = 0; kk < d.size(); kk++)
            {
                if(d[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'e':
            for(int kk = 0; kk < e.size(); kk++)
            {
                if(e[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'f':
            for(int kk = 0; kk < f.size(); kk++)
            {
                if(f[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'g':
            for(int kk = 0; kk < g.size(); kk++)
            {
                if(g[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'h':
            for(int kk = 0; kk < h.size(); kk++)
            {
                if(h[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'i':
            for(int kk = 0; kk < i.size(); kk++)
            {
                if(i[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'j':
            for(int kk = 0; kk < j.size(); kk++)
            {
                if(j[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'k':
            for(int kk = 0; kk < k.size(); kk++)
            {
                if(k[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'l':
            for(int kk = 0; kk < l.size(); kk++)
            {
                if(l[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'm':
            for(int kk = 0; kk < m.size(); kk++)
            {
                if(m[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'n':
            for(int kk = 0; kk < n.size(); kk++)
            {
                if(n[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'o':
            for(int kk = 0; kk < o.size(); kk++)
            {
                if(o[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'p':
            for(int kk = 0; kk < p.size(); kk++)
            {
                if(p[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'q':
            for(int kk = 0; kk < q.size(); kk++)
            {
                if(q[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'r':
            for(int kk = 0; kk < r.size(); kk++)
            {
                if(r[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 's':
            for(int kk = 0; kk < s.size(); kk++)
            {
                if(s[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 't':
            for(int kk = 0; kk < t.size(); kk++)
            {
                if(t[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'u':
            for(int kk = 0; kk < u.size(); kk++)
            {
                if(u[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'v':
            for(int kk = 0; kk < v.size(); kk++)
            {
                if(v[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'w':
            for(int kk = 0; kk < w.size(); kk++)
            {
                if(w[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'x':
            for(int kk = 0; kk < x.size(); kk++)
            {
                if(x[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'y':
            for(int kk = 0; kk < y.size(); kk++)
            {
                if(y[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'z':
            for(int kk = 0; kk < z.size(); kk++)
            {
                if(z[kk] == fiveLetterWords[jj])
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        }
    }
 //   vector<string> temp2;
    for(int i = 0; i < temp.size(); i++)
    {
        for(int j = 0; j < fiveLetterWords.size(); j++)
        {
            if(temp[i] == fiveLetterWords[j])
                fiveLetterWords.erase(fiveLetterWords.begin()+j);
        }
    }
//    fiveLetterWords.clear();
//    fiveLetterWords = temp2;
}
void getYellowElements(char letter, int position)
{
    vector<string> temp;
    for(int jj = 0; jj < fiveLetterWords.size(); jj++)
    {
        switch(letter)
        {
        case 'a':
            for(int kk = 0; kk < a.size(); kk++)
            {
                if(a[kk] == fiveLetterWords[jj] && a[kk][position] != 'a')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'b':
            for(int kk = 0; kk < b.size(); kk++)
            {
                if(b[kk] == fiveLetterWords[jj] && b[kk][position] != 'b')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'c':
            for(int kk = 0; kk < c.size(); kk++)
            {
                if(c[kk] == fiveLetterWords[jj] && c[kk][position] != 'c')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'd':
            for(int kk = 0; kk < d.size(); kk++)
            {
                if(d[kk] == fiveLetterWords[jj] && d[kk][position] != 'd')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'e':
            for(int kk = 0; kk < e.size(); kk++)
            {
                if(e[kk] == fiveLetterWords[jj] && e[kk][position] != 'e')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'f':
            for(int kk = 0; kk < f.size(); kk++)
            {
                if(f[kk] == fiveLetterWords[jj] && f[kk][position] != 'f')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'g':
            for(int kk = 0; kk < g.size(); kk++)
            {
                if(g[kk] == fiveLetterWords[jj] && g[kk][position] != 'g')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'h':
            for(int kk = 0; kk < h.size(); kk++)
            {
                if(h[kk] == fiveLetterWords[jj] && h[kk][position] != 'h')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'i':
            for(int kk = 0; kk < i.size(); kk++)
            {
                if(i[kk] == fiveLetterWords[jj] && i[kk][position] != 'i')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'j':
            for(int kk = 0; kk < j.size(); kk++)
            {
                if(j[kk] == fiveLetterWords[jj] && j[kk][position] != 'j')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'k':
            for(int kk = 0; kk < k.size(); kk++)
            {
                if(k[kk] == fiveLetterWords[jj] && k[kk][position] != 'k')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'l':
            for(int kk = 0; kk < l.size(); kk++)
            {
                if(l[kk] == fiveLetterWords[jj] && l[kk][position] != 'l')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'm':
            for(int kk = 0; kk < m.size(); kk++)
            {
                if(m[kk] == fiveLetterWords[jj] && m[kk][position] != 'm')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'n':
            for(int kk = 0; kk < n.size(); kk++)
            {
                if(n[kk] == fiveLetterWords[jj] && n[kk][position] != 'n')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'o':
            for(int kk = 0; kk < o.size(); kk++)
            {
                if(o[kk] == fiveLetterWords[jj] && o[kk][position] != 'o')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'p':
            for(int kk = 0; kk < p.size(); kk++)
            {
                if(p[kk] == fiveLetterWords[jj] && p[kk][position] != 'p')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'q':
            for(int kk = 0; kk < q.size(); kk++)
            {
                if(q[kk] == fiveLetterWords[jj] && q[kk][position] != 'q')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'r':
            for(int kk = 0; kk < r.size(); kk++)
            {
                if(r[kk] == fiveLetterWords[jj] && r[kk][position] != 'r')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 's':
            for(int kk = 0; kk < s.size(); kk++)
            {
                if(s[kk] == fiveLetterWords[jj] && s[kk][position] != 's')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 't':
            for(int kk = 0; kk < t.size(); kk++)
            {
                if(t[kk] == fiveLetterWords[jj] && t[kk][position] != 't')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'u':
            for(int kk = 0; kk < u.size(); kk++)
            {
                if(u[kk] == fiveLetterWords[jj] && u[kk][position] != 'u')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'v':
            for(int kk = 0; kk < v.size(); kk++)
            {
                if(v[kk] == fiveLetterWords[jj] && v[kk][position] != 'v')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'w':
            for(int kk = 0; kk < w.size(); kk++)
            {
                if(w[kk] == fiveLetterWords[jj] && w[kk][position] != 'w')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'x':
            for(int kk = 0; kk < x.size(); kk++)
            {
                if(x[kk] == fiveLetterWords[jj] && x[kk][position] != 'x')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'y':
            for(int kk = 0; kk < y.size(); kk++)
            {
                if(y[kk] == fiveLetterWords[jj] && y[kk][position] != 'y')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'z':
            for(int kk = 0; kk < z.size(); kk++)
            {
                if(z[kk] == fiveLetterWords[jj] && z[kk][position] != 'z')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        }
    }
    fiveLetterWords.clear();
    fiveLetterWords = temp;
}
void getGreenElements(char letter, int position)
{
    vector<string> temp;
    for(int jj = 0; jj < fiveLetterWords.size(); jj++)
    {
        switch(letter)
        {
        case 'a':
            for(int kk = 0; kk < a.size(); kk++)
            {
                if(a[kk] == fiveLetterWords[jj] && a[kk][position] == 'a')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'b':
            for(int kk = 0; kk < b.size(); kk++)
            {
                if(b[kk] == fiveLetterWords[jj] && b[kk][position] == 'b')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'c':
            for(int kk = 0; kk < c.size(); kk++)
            {
                if(c[kk] == fiveLetterWords[jj] && c[kk][position] == 'c')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'd':
            for(int kk = 0; kk < d.size(); kk++)
            {
                if(d[kk] == fiveLetterWords[jj] && d[kk][position] == 'd')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'e':
            for(int kk = 0; kk < e.size(); kk++)
            {
                if(e[kk] == fiveLetterWords[jj] && e[kk][position] == 'e')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'f':
            for(int kk = 0; kk < f.size(); kk++)
            {
                if(f[kk] == fiveLetterWords[jj] && f[kk][position] == 'f')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'g':
            for(int kk = 0; kk < g.size(); kk++)
            {
                if(g[kk] == fiveLetterWords[jj] && g[kk][position] == 'g')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'h':
            for(int kk = 0; kk < h.size(); kk++)
            {
                if(h[kk] == fiveLetterWords[jj] && h[kk][position] == 'h')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'i':
            for(int kk = 0; kk < i.size(); kk++)
            {
                if(i[kk] == fiveLetterWords[jj] && i[kk][position] == 'i')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'j':
            for(int kk = 0; kk < j.size(); kk++)
            {
                if(j[kk] == fiveLetterWords[jj] && j[kk][position] == 'j')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'k':
            for(int kk = 0; kk < k.size(); kk++)
            {
                if(k[kk] == fiveLetterWords[jj] && k[kk][position] == 'k')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'l':
            for(int kk = 0; kk < l.size(); kk++)
            {
                if(l[kk] == fiveLetterWords[jj] && l[kk][position] == 'l')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'm':
            for(int kk = 0; kk < m.size(); kk++)
            {
                if(m[kk] == fiveLetterWords[jj] && m[kk][position] == 'm')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'n':
            for(int kk = 0; kk < n.size(); kk++)
            {
                if(n[kk] == fiveLetterWords[jj] && n[kk][position] == 'n')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'o':
            for(int kk = 0; kk < o.size(); kk++)
            {
                if(o[kk] == fiveLetterWords[jj] && o[kk][position] == 'o')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'p':
            for(int kk = 0; kk < p.size(); kk++)
            {
                if(p[kk] == fiveLetterWords[jj] && p[kk][position] == 'p')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'q':
            for(int kk = 0; kk < q.size(); kk++)
            {
                if(q[kk] == fiveLetterWords[jj] && q[kk][position] == 'q')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'r':
            for(int kk = 0; kk < r.size(); kk++)
            {
                if(r[kk] == fiveLetterWords[jj] && r[kk][position] == 'r')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 's':
            for(int kk = 0; kk < s.size(); kk++)
            {
                if(s[kk] == fiveLetterWords[jj] && s[kk][position] == 's')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 't':
            for(int kk = 0; kk < t.size(); kk++)
            {
                if(t[kk] == fiveLetterWords[jj] && t[kk][position] == 't')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'u':
            for(int kk = 0; kk < u.size(); kk++)
            {
                if(u[kk] == fiveLetterWords[jj] && u[kk][position] == 'u')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'v':
            for(int kk = 0; kk < v.size(); kk++)
            {
                if(v[kk] == fiveLetterWords[jj] && v[kk][position] == 'v')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'w':
            for(int kk = 0; kk < w.size(); kk++)
            {
                if(w[kk] == fiveLetterWords[jj] && w[kk][position] == 'w')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'x':
            for(int kk = 0; kk < x.size(); kk++)
            {
                if(x[kk] == fiveLetterWords[jj] && x[kk][position] == 'x')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'y':
            for(int kk = 0; kk < y.size(); kk++)
            {
                if(y[kk] == fiveLetterWords[jj] && y[kk][position] == 'y')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        case 'z':
            for(int kk = 0; kk < z.size(); kk++)
            {
                if(z[kk] == fiveLetterWords[jj] && z[kk][position] == 'z')
                        temp.push_back(fiveLetterWords[jj]);
            }
            break;
        }
    }
    fiveLetterWords.clear();
    fiveLetterWords = temp;

}
void removeDuplicates()
{
    sort( fiveLetterWords.begin(), fiveLetterWords.end() );
    fiveLetterWords.erase( unique( fiveLetterWords.begin(), fiveLetterWords.end() ), fiveLetterWords.end() );
}
