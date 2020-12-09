#include<iostream>
#include<vector>

using namespace std;

int main(){
	int arr[5] = {};
	vector<int> vec1;
	vector<int> vec2(5); // 初始size= n 的vector，並且填滿0或\0
	vector<int> vec3(arr,arr+2); // 將int*類別陣列賦予給vector
	vector<int> vec4(5,2); // 將vec做初始化，將size = count，且塞滿元素val
	
	// 要使用iterator前必須要在前面加上要指定的scope resolution operator(::)
	vector<int>::iterator itr;
	itr=vec4.begin(); // 將vector的第零個元素位址綁定給iterator，之後就可以直接存取值了
	
	cout<<vec4.size()<<endl; // 回傳擁有的元素個數
	cout<<vec4.capacity()<<endl; // 回傳最大可擁有的元素個數，此值只會越來越大不會變小
	cout<<vec4.empty()<<endl; // 若為空，回傳true
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; //利用iterator進行第i個元素存取，就如同pointer一樣加個*即可使用
	// .end()指向 vector 最尾端元素的下一個位置
	cout<<endl;
	
	cout<<vec4[0]<<endl; // 如同一般array樣，存取index為i的元素
	cout<<vec4.at(4)<<endl; //vector本身的方法，存取時會做邊界檢查(檢查size)，如果超過邊界會拋出一個例外，這是和[]的差別
	
	cout<<vec4.front()<<endl; // 回傳 vector 第一個元素值(同 vec.at(0))
	cout<<vec4.back()<<endl; //回傳 vector 最尾端元素值(同 vec.at(vec.size()-1) )
	
	itr=vec4.begin();
	cout<<*itr<<endl;
	cout<<*(itr+1)<<endl; //利用iterator進行第i個元素存取，就如同pointer一樣加個*即可使用		
	//不要用vec[i]與vec.at(i)進行元素新增，因為雙方都不會改變size值，只能對已存在的元素進行修改!!!!(前者不會報錯，後者會報錯)
	
	
	vec4.push_back(50); //核心函式。將元素n塞至vector的尾端並size+1。若size超過capacity時會再進行記憶體配置。
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.pop_back(); //刪除vector最尾端的元素，size會-1。很像stack的pop
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	itr=vec4.begin();
	vec4.insert(itr,50); //將元素n插入至vector內pos的位置
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.push_back(50);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.erase(vec4.end()-1); //刪除 vector 中位置pos的元素
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	
	vec4.push_back(49);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.erase(vec4.begin(),vec4.begin()+2); //刪除 vector 中位置first~last-1的元素
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;


	vec4.clear(); //清空所有元素
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	
	vec4.push_back(1);
	vec4.push_back(2);
	vec4.push_back(3);
	vec4.push_back(4);
	vec4.push_back(5);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.reserve(2); //改變vector整體的最大容量(capacity)為n，且n必須大於capacity，也就是只能變大，否則不會做事。類似realloc
	cout<<vec4.capacity()<<endl;
	vec4.reserve(15);
	cout<<vec4.capacity()<<endl;
	
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.resize(6); //改變vector的擁有元素數(size)成n。size變少時多的元素會被移除；變多時則是補0(或\0)。類似calloc
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.resize(4);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	//若resize的大小大於原本的capacity，vector也會跟著重新分配記憶體
	
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	for(itr=vec2.begin(); itr<vec2.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.swap(vec2); //vec2和vec4為相同類別的vector。此方法可以將兩個長度不同的vector做內容交換
	
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	for(itr=vec2.begin(); itr<vec2.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	for(auto i:vec4) cout<<i<<" ";
	cout<<endl;
	
	vec4.clear();
	vector<int>().swap(vec4); // 宣告一個空vector，將其與要刪除的vector進行swap交換，就能做記憶體刪除
	
	//push_back()在發現capacity不夠時，會將該vector記憶體做雙倍大小重新配置，因此若重新分配太多次後，會導致記憶體過度浪費與過多不必要的記憶體重新配置，因此若能知道要用多少的記憶體，或最多會用多少時，還是建議直接先使用reserve(n)進行記憶體配置
	//因為operator[]不會進行邊界檢查，若程式過於龐大，出錯時會很難找出錯誤，建議還是使用at(i)
	
	
	
	// 一般二維array
	int arr1[3][2] = {{1, 2}, {3, 4},{ 5, 6}};
	// 動態二維vector -> 給予vec初始值為 3個"長度為2的int vector(並給初值為0)"
	vector<vector<int> > vec(3, vector<int>(2));
	// do whatever you want like array;
	for(int i=0; i<3; i++)
	    for(int j=0; j<2; j++)
	        (vec.at(i)).at(j) = arr1[i][j];    // vec.at(i).at(j)同vec[i][j]	
	//因為">>"是關鍵operator，因此宣告時兩個">"之間，一定要有空格!
	
	
	for(auto i:vec){
		for(auto j:i){
			cout<<j<<" ";
		}
	}
	cout<<endl;
	
	
	//用push_back
	// 一般二維array
	int arr2[3][2] = {1, 2, 3, 4, 5, 6};
	// 乾淨的二維vector
	vector<vector<int> > vec0;
	for(int i=0; i<3; i++)
	{
	    vector<int> row;
	    for(int j=0; j<2; j++)
	        row.push_back(arr2[i][j]);
	    vec0.push_back(row);
	}
	
	
	//把vector當參數傳時, 等於pass by value 
	//需要pass by address or pass by reference 
} 

