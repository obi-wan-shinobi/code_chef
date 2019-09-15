#include <bits/stdc++.h>
using namespace std;

vector<int> alter(vector<int>);

int main() {
	vector<int> myvec;
	int tscases, dig, it;
	cin>>tscases;
	if(tscases>1000)
	    return 0;
	while(tscases>0)
	{
	    cin>>dig>>it;
	    if(dig > 1000000)
	        return 0;
	    if(it > 1000000)
	        return 0;
	    int temp;
	    while(dig>0)
	    {
        cin>>temp;
	    	myvec.push_back(temp);
	    	dig--;
	    }
	    while(it>0)
	    {
	        myvec = alter(myvec);
	        it--;
	    }

	    for(auto i=myvec.begin(); i!=myvec.end(); ++i)
	        cout<<*i<<"\t";

			myvec.clear();
	    cout<<endl;
			tscases--;
	}
	return 0;
}

vector<int> alter(vector<int> sample)
{
		vector<int> result;
		result = sample;
    for(int i=0; i<sample.size()-1; i++)
    {
        if(sample[i]==0 && sample[i+1]==1)
        {
						int temp=result[i];
						result[i] = result[i+1];
						result[i+1]=temp;
        }
    }
    return result;
}
