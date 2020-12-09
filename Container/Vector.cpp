#include<iostream>
#include<vector>

using namespace std;

int main(){
	int arr[5] = {};
	vector<int> vec1;
	vector<int> vec2(5); // ��lsize= n ��vector�A�åB��0��\0
	vector<int> vec3(arr,arr+2); // �Nint*���O�}�C�ᤩ��vector
	vector<int> vec4(5,2); // �Nvec����l�ơA�Nsize = count�A�B�뺡����val
	
	// �n�ϥ�iterator�e�����n�b�e���[�W�n���w��scope resolution operator(::)
	vector<int>::iterator itr;
	itr=vec4.begin(); // �Nvector���Ĺs�Ӥ�����}�j�w��iterator�A����N�i�H�����s���ȤF
	
	cout<<vec4.size()<<endl; // �^�Ǿ֦��������Ӽ�
	cout<<vec4.capacity()<<endl; // �^�ǳ̤j�i�֦��������ӼơA���ȥu�|�V�ӶV�j���|�ܤp
	cout<<vec4.empty()<<endl; // �Y���šA�^��true
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; //�Q��iterator�i���i�Ӥ����s���A�N�p�Ppointer�@�˥[��*�Y�i�ϥ�
	// .end()���V vector �̧��ݤ������U�@�Ӧ�m
	cout<<endl;
	
	cout<<vec4[0]<<endl; // �p�P�@��array�ˡA�s��index��i������
	cout<<vec4.at(4)<<endl; //vector��������k�A�s���ɷ|������ˬd(�ˬdsize)�A�p�G�W�L��ɷ|�ߥX�@�Өҥ~�A�o�O�M[]���t�O
	
	cout<<vec4.front()<<endl; // �^�� vector �Ĥ@�Ӥ�����(�P vec.at(0))
	cout<<vec4.back()<<endl; //�^�� vector �̧��ݤ�����(�P vec.at(vec.size()-1) )
	
	itr=vec4.begin();
	cout<<*itr<<endl;
	cout<<*(itr+1)<<endl; //�Q��iterator�i���i�Ӥ����s���A�N�p�Ppointer�@�˥[��*�Y�i�ϥ�		
	//���n��vec[i]�Pvec.at(i)�i�椸���s�W�A�]�����賣���|����size�ȡA�u���w�s�b�������i��ק�!!!!(�e�̤��|�����A��̷|����)
	
	
	vec4.push_back(50); //�֤ߨ禡�C�N����n���vector�����ݨ�size+1�C�Ysize�W�Lcapacity�ɷ|�A�i��O����t�m�C
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.pop_back(); //�R��vector�̧��ݪ������Asize�|-1�C�ܹ�stack��pop
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	itr=vec4.begin();
	vec4.insert(itr,50); //�N����n���J��vector��pos����m
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.push_back(50);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.erase(vec4.end()-1); //�R�� vector ����mpos������
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	
	vec4.push_back(49);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.erase(vec4.begin(),vec4.begin()+2); //�R�� vector ����mfirst~last-1������
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;


	vec4.clear(); //�M�ũҦ�����
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	
	vec4.push_back(1);
	vec4.push_back(2);
	vec4.push_back(3);
	vec4.push_back(4);
	vec4.push_back(5);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.reserve(2); //����vector���骺�̤j�e�q(capacity)��n�A�Bn�����j��capacity�A�]�N�O�u���ܤj�A�_�h���|���ơC����realloc
	cout<<vec4.capacity()<<endl;
	vec4.reserve(15);
	cout<<vec4.capacity()<<endl;
	
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.resize(6); //����vector���֦�������(size)��n�Csize�ܤ֮ɦh�������|�Q�����F�ܦh�ɫh�O��0(��\0)�C����calloc
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	vec4.resize(4);
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	//�Yresize���j�p�j��쥻��capacity�Avector�]�|��ۭ��s���t�O����
	
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	for(itr=vec2.begin(); itr<vec2.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	vec4.swap(vec2); //vec2�Mvec4���ۦP���O��vector�C����k�i�H�N��Ӫ��פ��P��vector�����e�洫
	
	for(itr=vec4.begin(); itr<vec4.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	for(itr=vec2.begin(); itr<vec2.end(); itr++) cout<<*itr<<" "; 
	cout<<endl;
	
	for(auto i:vec4) cout<<i<<" ";
	cout<<endl;
	
	vec4.clear();
	vector<int>().swap(vec4); // �ŧi�@�Ӫ�vector�A�N��P�n�R����vector�i��swap�洫�A�N�వ�O����R��
	
	//push_back()�b�o�{capacity�����ɡA�|�N��vector�O���鰵�����j�p���s�t�m�A�]���Y���s���t�Ӧh����A�|�ɭP�O����L�׮��O�P�L�h�����n���O���魫�s�t�m�A�]���Y�ા�D�n�Φh�֪��O����A�γ̦h�|�Φh�֮ɡA�٬O��ĳ�������ϥ�reserve(n)�i��O����t�m
	//�]��operator[]���|�i������ˬd�A�Y�{���L���e�j�A�X���ɷ|������X���~�A��ĳ�٬O�ϥ�at(i)
	
	
	
	// �@��G��array
	int arr1[3][2] = {{1, 2}, {3, 4},{ 5, 6}};
	// �ʺA�G��vector -> ����vec��l�Ȭ� 3��"���׬�2��int vector(�õ���Ȭ�0)"
	vector<vector<int> > vec(3, vector<int>(2));
	// do whatever you want like array;
	for(int i=0; i<3; i++)
	    for(int j=0; j<2; j++)
	        (vec.at(i)).at(j) = arr1[i][j];    // vec.at(i).at(j)�Pvec[i][j]	
	//�]��">>"�O����operator�A�]���ŧi�ɨ��">"�����A�@�w�n���Ů�!
	
	
	for(auto i:vec){
		for(auto j:i){
			cout<<j<<" ";
		}
	}
	cout<<endl;
	
	
	//��push_back
	// �@��G��array
	int arr2[3][2] = {1, 2, 3, 4, 5, 6};
	// ���b���G��vector
	vector<vector<int> > vec0;
	for(int i=0; i<3; i++)
	{
	    vector<int> row;
	    for(int j=0; j<2; j++)
	        row.push_back(arr2[i][j]);
	    vec0.push_back(row);
	}
	
	
	//��vector��ѼƶǮ�, ����pass by value 
	//�ݭnpass by address or pass by reference 
} 

