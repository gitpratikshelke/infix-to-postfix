#include"Stack.cpp"
class exp
{
char inf[10],post[10];
    public :
    void inf2post();
    void inf2pref();
    int posteval();
    int preeval();


};
int icp(char x)
    {
        if(x=='+'||x=='-')
        return 1;
        else if(x=='*'||x=='/')
        return 2;
        else if(x=='^')
        return 3;
        else if(x==')')
        return 4;
        else
            return 5;
    }

    int isp(char x)
    {
        if(x=='+'||x=='-')
        return 1;
        else if(x=='*'||x=='/')
        return 2;
        else if(x=='^')
        return 3;
        else if(x=='(')
        return 0;
        else
            return 4;
    }


void exp::inf2post()
{
    stack s;
    int i,j=0;
    cout<<"enter infix expression: ";
    cin>>inf;
    for(int i=0;inf[i]!='\0';i++)
    {
        int x;
        x=inf[i];
        if(isalnum(x))
        post[j++]=x;
        else if(x=='(')
        s.push(x);
        else if(x==')')
        {
            while(x=s.pop()!='(')
            post[j++]=x;
        }
        else{
            while(!s.isEmpty()&&icp(x)<=isp(s.showTop()))
            {
                post[j++]=s.pop();
            }
            s.push(x);
            }

    }

            while(!s.isEmpty())
                post[j++]=s.pop();
            post[j]='\0';
            cout<<"postfix="<<post;

        }




int main()
  {


  	exp e;
  	e.inf2post();

  }
