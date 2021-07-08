#include<iostream>
#include<string>
#include<vector>
//#include<cstdlib>
//#include<sstream>
#include<fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include<dirent.h>
#include<cstdio>
//#include<map>
//#include<iterator>
#include<algorithm>
#include<cstring>
//#include<set>
#include<cctype>
#include <bits/stdc++.h>
using namespace std;
struct lmsbook
{
    int sno;
    string nBook;
    string tBook;
    string aBook;
    string tyBook;
};
struct stat info;
struct nov
{
    int coun;
    string par;
};
bool isUpper(const std::string s) {
    int c=0,d;
    for(int i=0;i<s.length()-1;i++)
    {
        if(isupper(s[i]) || isspace(s[i]) || s[i] == '\'')
            c++;
            if(islower(s[i]))
            d++;
    }
    if((c+1)==s.length())// || c>d)
        return 1;
    return 0;
}
class book
{
    string title, author, filename, type;
public:
    void createBook(string s)
    {
        fstream file1;
       string fil = s,ti,ty,line;
        cout<<"\n-->ENTER THE NAME OF THE BOOK: ";
        cin>>ti;
        cout<<"\n-->ENTER THE TYPE OF THE BOOK: ";
        cin>>ty;
        fil = fil + "\\" + ti + ".txt";
        file1.open(fil.c_str(),ios::out);
        cout<<"\n-->ENTER THE BOOK: ";
        while(getline(cin,line))
        {
            if(line == "EOF")
                    break;
                file1<<line<<endl;
        }
        file1.close();

    }
    string getType(string s)
    {
        fstream file1;
      string word,name = "";int c=0,d=0;
      file1.open(s.c_str(),ios::in);
      while ( file1>>word )
                       {
                           if(word == "CHAPTER")c++;
                           if(word=="ACT")d++;
                                  }
                            file1.close();
                            if(c>d)
                                name = "Novel";
                            else if(d>c)
                                name = "Play";
                           return name;
    }
    string getTitle(string s)
    {
      fstream file1;
      string word,name = "";
      file1.open(s.c_str(),ios::in);
      while ( file1>>word )
                       {
                           if(word == "Title:")
                           {
                                while(1){
                                file1>>word;
                                if(word == "Author:")
                                    break;
                                name = name + " " + word;
                               }
                             // a =  name;
                              break;
                           }         }
                            file1.close();
                           return name;
    }
    string getAuthor(string s)
    {
      fstream file1;
      string word,Aname;
      file1.open(s.c_str(),ios::in);
      while ( file1>>word )
                       {
                           if(word == "Author:")
                           {
                                while(1){
                                file1>>word;
                                if(word == "Release")
                                    break;
                                Aname = Aname + " " + word;
                               }
                             // a =  name;
                              break;
                           }         }
                            file1.close();
                           return Aname;
    }
    display(string s, string d)
    {
        fstream file1;
        string line;
        d = d + "/" +s  ;
        cout<<d<<endl;
        file1.open(d.c_str(),ios::in);
        while(getline(file1,line))
            cout<<line<<endl;
    }
};
struct lmsbook* indx(string s, int& n)
{
  struct lmsbook* mam= new struct lmsbook[100];
    DIR *pDIR;
        struct dirent *entry;book b;
        string a,e,direntry=s,y,x;int i=0;
        fstream file;
        string dirz = s ;
        dirz = dirz +"/index.txt";
        file.open(dirz.c_str(),ios::out|ios::trunc);
    if( pDIR=opendir(s.c_str()) ){
                while(entry = readdir(pDIR)){
                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, ".." ) != 0 && strcmp(entry->d_name, "index.txt") != 0 ){
                                i++;
                                direntry = s + "\\" + entry->d_name;
                                a = b.getTitle(direntry);
                                y = b.getAuthor(direntry);
                                e = b.getType(direntry);
                                mam[i].sno = i;
                                mam[i].nBook = entry->d_name;
                                mam[i].tBook = a;
                                mam[i].aBook = y;
                                mam[i].tyBook = e;
                                file<<i<<"."<<"Title:"<<a<<"\t\tType:"<<e<<endl;
                                }}}
                                n = i;
                                closedir(pDIR);
                                return mam;
}
void searchNovel(string s, string word, string d)
   {
       fstream file1;
        string line, para;
        int i=0,c=0,x=0;
        vector<int>vec;
        struct nov non[500];
        d = d + "/" +s  ;
        file1.open(d.c_str(),ios::in);
        while(file1>>line)
        {
            if(line != "CHAPTER")
                para = para + " " + line;
                if(line == word)
                    i++;
            if(line == "CHAPTER")
            {
               non[c].par = para;
               non[c].coun = i;
               vec.push_back(i);
               i=0;
               file1>>line;
               para = line;
               c++;
            }}
        sort(vec.begin(), vec.end(), greater<int>());
        for(int m=0;m<5;m++)
        {
            if(vec[m]!=0){
            for(int n=0;n<c;n++)
            {
                //if(x==5)break;
                if(vec[m] == non[n].coun){
                    cout<<"....Number of times the word appears:"<<non[n].coun<<"....\nCHAPTER "<<non[n].par<<"\n\n"<<endl;
                     non[n].coun =0;
                    break;}
            }}}}

       void  searchPlay(string s, string word, string d)
        {
        fstream file1;
        string line, chars[2000], cc[2000],lin,w, fin = "SCENE", l,z;
        w = word +".";
        int i=0,c=0,fos=0,zen =0, pos=0,ppos=0 , index, ind;static int fo = 0;
        d = d + "/" +s  ;
        //
        file1.open(d.c_str(),ios::in);
        while(getline(file1, line))
        {
              pos = 0;
            if((index = line.find(fin, pos)) != string::npos || zen == 1)
            {  //;
                fos=0;c=0;//pos = 0;
                while(getline(file1, line)){ pos=0;

                if((ind = line.find(fin, pos)) != string::npos){
                        zen =1;
                        break;
                        }
                else
                    zen = 0;
                    ppos = 0;
                    int ppos = line.find(".");
                    //int pprops = linr.find("and");
                    if(ppos != string::npos){
                     l = line.substr(0, ppos+1);
                      //cout<<l<<endl;
                if ( l != "ACT" && l != "SCENE" && isUpper(l)==1 && l.length()>2 && l != "BOTH." && l != "ALL."&& l != "CHORUS."){
                             chars[c] = l;
                             // cout<<chars[c]<<endl;
                             c++;
                             }}}
               // cout<<"c="<<c<<endl;


            for(int ef=0;ef<c;ef++)
            {
                if(chars[ef] == w || chars[ef] == word)
                    fos = 1;
                    //cout<<chars[ef]<<" ";
            }
           // cout<<"fos="<<fos<<endl;
           // cout<<"fo="<<fo<<endl;
            if(fos){
                    int zzz=0;
            for(int no=fo;no<fo+c;no++)
            {
              cc[no] = chars[zzz];
            zzz++;
            }
            fo = fo+c+1;
            }

             // cout<<"fo="<<fo<<endl;
            }
        }
       /*  while(file1>>line)
        {
            if(line == "SCENE")
            {
              while(file1>>line)
                {
                if(line == w)
            {
                while(file1>>line){
                if(line == "SCENE" )
                        break;
                    if ( line != word && line!=w && line != "ACT" && line != "SCENE" && isUpper(line)==1 && line.length()>3 && line != "BOTH." && line != "ALL."){
                             chars[c] = line;
                      c++;}
                      }}
             if(line == "SCENE" )
                        break;
                        }
        }
        }*/
        for(i=0;i<fo;i++)
        {
            for(int j=i+1;j<fo;j++)
            {
                if(cc[i] == cc[j] || cc[i] == (cc[j]+".") || (cc[i] + ".") == (cc[j]))// || cc[j] == word || cc[j] == w)
                    cc[j] = ".";
                    /*if((index = cc[i].find(cc[j], pos)) != string::npos && index!=0)
                    {
                        int ppos = line.find("and");
                    //int pprops = linr.find("and");
                    if(ppos != string::npos){
                     l = line.substr(0, ppos);
                     z = line. substr(pos+4);
                    }
                        cc[fo+1] = l;
                        cc[fo+2] = z;
                        fo = fo+2;
                    }*/
            }
        }int xo=0;
        cout<<"\n.....Characters that appear with "<<word<<" in at least one scene are.....\n";
        for(int g=0;g<fo;g++)
        {

            if(cc[g]!="." && cc[g]!=word && cc[g]!=w && cc[g]!=" "){
            cout<<cc[g]<<endl;}
        }
        }
main()
{
        struct lmsbook *mame;
        string dirname,a,au,acti;
        string fin,ff,wor,nnn; int fi,nn,n;
        cout<<"==>ENTER THE DIRECTORY:"<<endl;
            cin>>dirname;

        //map<string, string> m=
        mame = indx(dirname,n);
      book b1;
      int i=0,f;
      while(1){

                                cout<<"\n==>SELECT AN ACTION:"<<endl;
                                cout<<"==>ENTER [1] TO CREATE A BOOK AND ADD IT TO THE CURRENT DIRECTORY"<<endl;
                                cout<<"==>ENTER [2] TO DISPLAY ALL BOOKS IN THE CURRENT DIRECTORY"<<endl;
                                cout<<"==>ENTER [3] TO SEARCH FOR A BOOK BY ITS TITLE OR AUTHOR"<<endl;
                                cout<<"==>ENTER [4] TO SELECT A BOOK(NOVEL/PLAY):"<<endl;
                                cout<<"==>ENTER [0] TO EXIT\n"<<endl;
                                cin>>f;
                                cout<<"\n";
                                if(f==0)
                                    break;
                                if(f==1){
                               b1.createBook(dirname);
                              mame = indx(dirname,n);
                              cout<<"\n==>BOOK CREATED AND ADDED TO THE DIRECTORY"<<endl;
                                }
                              if (f==2)
                              {

                                  for(int j=1;j<=n;j++)
                                    cout<<"\n  "<<j<<"."<<"\n\t-FILENAME: "<<mame[j].nBook<<"\n\t-TITLE:"<<mame[j].tBook<<"\n\t-AUTHOR: "<<mame[j].aBook<<endl;
                              }
                              if(f==3)
                              {
                                  cout<<"==>SELECT:\n\t1.TITLE\n\t2.AUTHOR\n"<<endl;
                                  cin>>nn;
                                  cin.ignore();
                                  getline(cin,fin);
                                  fin = " "+fin;int pos=0, index;
                                  cout<<"\n==>ITEMS THAT MATCH YOUR SEARCH ARE:\n"<<endl;
                                    for(int j=1;j<=n;j++)
                                    {
                                        if(fin == mame[j].tBook || fin == mame[j].aBook || (index = mame[j].tBook.find(fin, pos)) != string::npos || (index = mame[j].aBook.find(fin, pos)) != string::npos)
                                    cout<<" -->TITLE: "<<mame[j].tBook<<"\tAUTHOR: "<<mame[j].aBook<<endl;
                                  }}
                                  if(f==2||f==3)
                                  {
                                      cout<<"\n==>SELECT A BOOK FROM THE ABOVE LIST TO DISPLAY(none to exit):"<<endl;
                                      cin.ignore();
                                      getline(cin,fin);
                                      if(fin == "none")continue;
                                      fin = " "+fin;
                                      for(int j=1;j<=n;j++){
                                      if(fin == mame[j].tBook )
                                        b1.display(mame[j].nBook,dirname);
                                      }}
                                      if(f==4)
                                      {
                                      cout<<"\n-->ENTER THE NAME OF NOVEL/PLAY:\n ";
                                      cin.ignore();
                                      getline(cin,fin);
                                      if(fin == "exit")
                                        break;
                                        fin = " "+fin;

                                      //cout<<fin<<nnn<<endl;
                                      for(int j=1;j<=n;j++)
                                    {
                                        if(fin == mame[j].tBook)
                                          {   // cout<<fin<<nnn<<endl;
                                              if(mame[j].tyBook == "Novel"){
                                                    cout<<"\n-->ENTER A WORD TO PRINT TOP 5 CHAPTERS WHERE THE WORD APPEARS MOST NUMBER OF TIMES:";
                                              getline(cin,nnn);
                                                searchNovel(mame[j].nBook,nnn,dirname);
                                              }
                                              else if(mame[j].tyBook == "Play"){
                                                     cout<<"\n-->ENTER A CHARACTER TO PRINT A LIST OF CHARACTERS PRESENT IN AT LEAST ONE SCENE WITH THE CHARACTER\n"<<endl;
                                                       getline(cin,nnn);
                                                searchPlay(mame[j].nBook,nnn,dirname);
                                              }
                                          }}}}}
