#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[55];
		scanf("%s",s);
		int temp,ans=1;
		for(int i=0;s[i+1]!='\0';i++)
		{
			if((s[i] == 'a' && s[i+1] == 'z') || (s[i] == 'z' && s[i+1] == 'a'))
			{
				ans = 1;
				continue;
			}
			temp = s[i] - s[i+1];
			if(temp == 1 || temp == -1)
				ans = 1;
			else
			{
				ans = 0;
				break;
			}
		}
		if(ans == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
