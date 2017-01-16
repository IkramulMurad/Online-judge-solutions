#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        string s;
        cin>>s;
        bool flag=1;
 
        for(int i=0; i<s.size(); ++i){
            if(s[i]!='9'){
                flag=0;
                break;
            }
        }
 
        if(flag){
            printf("Case %d: ",t);
            printf("1");
            for(int i=0; i<s.size()-1; ++i){
                printf("0");
            }
            printf("1\n");
            continue;
        }
 
        else if(s.size()==1){
            printf("Case %d: %c\n",t,s[0]+1);
            continue;
        }
 
        else{
            if(s.size()&1){
                int mid=s.size()/2;
                int spflag=0;
                for(int i=mid-1, j=mid+1; i>=0; --i,++j){
                    if(s[i]<s[j]){
                        spflag=0;
                        break;
                    }
                    else if(s[i]>s[j]){
                        spflag=1;
                        break;
                    }
                }
                if(spflag){
                    printf("Case %d: ",t);
                    for(int i=0; i<=mid; ++i){
                        printf("%c",s[i]);
                    }
                    for(int i=mid-1; i>=0; --i){
                        printf("%c",s[i]);
                    }
                    printf("\n");
                    continue;
                }
                int carry=0;
 
                if(s[mid]=='9'){
                    s[mid]='0';
                    carry=1;
                }
                else s[mid]=s[mid]+1;
 
                for(int i=mid-1,j=mid+1; i>=0; --i,++j){
                    if(carry){
                        if(s[i]!='9') carry=0;
                        int x=(s[i]-48+1)%10;
                        s[i]=x+48;
                        s[j]=s[i];
                        continue;
                    }
                    s[j]=s[i];
                }
            }
            else{
                int mid2=s.size()/2, mid1=mid2-1;
 
                int spflag=0;
                for(int i=mid1, j=mid2; i>=0; --i,++j){
                    if(s[i]<s[j]){
                        spflag=0;
                        break;
                    }
                    else if(s[i]>s[j]){
                        spflag=1;
                        break;
                    }
 
                }
                if(spflag){
                    printf("Case %d: ",t);
                    for(int i=0; i<=mid1; ++i){
                        printf("%c",s[i]);
                    }
                    for(int i=mid1; i>=0; --i){
                        printf("%c",s[i]);
                    }
                    printf("\n");
                    continue;
                }
 
                int carry=0;
                if(s[mid1]>s[mid2]) s[mid2]=s[mid1];
                else if(s[mid1]<s[mid2]){
                    s[mid1]=s[mid1]+1;
                    s[mid2]=s[mid1];
                }
                else{
 
                    if(s[mid1]=='9'){
                        s[mid1]=s[mid2]='0';
                        carry=1;
                    }
                    else{
                        s[mid1]=s[mid2]=s[mid2]+1;
                    }
                }
                for(int i=mid1-1,j=mid2+1; i>=0; --i,++j){
                    if(carry){
                        if(s[i]!='9') carry=0;
                        int x=(s[i]-48+1)%10;
                        s[i]=x+48;
                        s[j]=s[i];
                        continue;
                    }
                    s[j]=s[i];
                }
 
            }
        }
        printf("Case %d: ",t);
        cout<<s;
        printf("\n");
    }
    return 0;
}
