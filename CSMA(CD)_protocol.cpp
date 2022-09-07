#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std; // only on windows pc, for sleep() function
#define kmax 15
int main()
{ int ChannelStatus;
float POutcome;
int flag = 0;
int i = 0;
int k, tp, tfr,tb;
int ack = 0;
k = 0;
int r; cout<<"Enter K, Max prop time, Avg frame time, back off time \n";
cin>>k>>tp>>tfr>>tb;
while(i < k)
{ cout<<"Sending the Frame \n"; cout<<"Waiting the TIME-OUT time ... \n";
Sleep(2*tp); // put csma here
while(flag == 0)
{ cout<<"1 for idle, 0 for busy \n" ;
cin>>ChannelStatus;
if(ChannelStatus == 1)
{ cout<<"Probabiltty outcome? \n";
cin>>POutcome;
if(POutcome <= 0.95) // 0.95 is arbitrary
{ cout<<"Transmitted";
flag = 1;
break;
}
else
{ cout<<"Waiting a slot... \n";
}
}
}
if(flag == 1)
{ cout<<"Success";
Sleep(2000); // wait to show success, exit;
exit(0);
}
else
{
i++;
// r is random wait time
r = rand() % (int)pow(2,k); cout<<"Waiting Tb time\n";
Sleep(r*tp);
}
}
if(ack == 0) cout<<"Aborted";
}
