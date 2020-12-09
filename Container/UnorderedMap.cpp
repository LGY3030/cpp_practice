#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	unordered_map<string, int> umap = {{"Jim", 1}, {"James", 2}, {"Curry", 3}}; //Initialize
	umap["Westbrook"] = 4; //Insert
	
	
	cout<<umap.at("Jim")<<endl;
	cout<<umap["Jim"]<<endl;
	//cout<<umap.at("Jimmy")<<endl; // 沒有key時, 會報錯 
	//cout<<umap["Jimmy"]<<endl; //  沒有key時, 不會報錯
	
	cout<<"Size:"<<umap.size()<<endl;
	cout<<"Empty:"<<umap.empty()<<endl;
	//cout<<"Maxsize:"<<umap.max_size()<<endl;
	
	unordered_map<string, int>::iterator itr;
	for(itr=umap.begin(); itr!=umap.end(); itr++){
		cout<<itr->first<<" "<<itr->second<<endl;;
	}
	cout<<"---------------------"<<endl;
	for(auto i: umap) cout<<i.first<<" "<<i.second<<endl;
	cout<<"---------------------"<<endl;
	
	for(pair<string, int> i: umap)  cout<<i.first<<" "<<i.second<<endl;
	cout<<"---------------------"<<endl;
	
	if(umap.find("Jim") == umap.end()) cout<<"not in the map"<<endl; //find會return iterator, 沒找到會return end 
	else cout<<"in the map"<<endl;
	
	if(umap.find("Jimmy") == umap.end()) cout<<"not in the map"<<endl;
	else cout<<"in the map"<<endl;
	
	umap.insert(pair<string, int>("Jay", 5));
	
	for(auto i: umap) cout<<i.first<<" "<<i.second<<endl;
	cout<<"---------------------"<<endl;
	umap.erase(umap.begin());
	for(auto i: umap) cout<<i.first<<" "<<i.second<<endl;
	cout<<"---------------------"<<endl;
	umap.erase("Jim");
	for(auto i: umap) cout<<i.first<<" "<<i.second<<endl;
	
}
