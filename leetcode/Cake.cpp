#include <iostream>

using namespace std;
class Solution{
	public:
		
		Solution(){
			m_nCakeCnt = 0;
			m_nMaxSwap = 0;
		}
		~Solution(){
			if(m_CakeArray!=NULL)	delete m_CakeArray;
			if(m_SwapArray!=NULL)	delete m_SwapArray;
			if(m_ReverseCakeArray!=NULL)	delete m_ReverseCakeArray;
			if(m_ReverseCakeArraySwap!=NULL)	delete m_ReverseCakeArraySwap;
		}
		void Search(int step){
			m_nSearch++;
			int nEstimate = LowerBound(m_ReverseCakeArray,m_nCakeCnt);
			if(step+nEstimate>m_nMaxSwap)	return;
			if(IsSorted(m_ReverseCakeArray,m_nCakeCnt)){
				if(step<m_nMaxSwap){
					m_nMaxSwap = step;
					for(int i=0;i<m_nMaxSwap;i++){
						m_SwapArray[i] = m_ReverseCakeArraySwap[i];
					}
					
				}
				return;
			}
			for(int i=1;i<m_nCakeCnt;i++){
				Reverse(0,i);
				m_ReverseCakeArraySwap[step] = i;
				Search(step+1);
				Reverse(0,i);
			}
		}
		
		void Reverse(int nBegin,int nEnd){
			int i,j,t;
			for(i=nBegin,j=nEnd;i<j;i++,j--){
				t = m_ReverseCakeArray[i];
				m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
				m_ReverseCakeArray[j] = t;
			}
		}
		
		bool IsSorted(int* pCakeArray,int nCakeCnt){
			for(int i=1;i<nCakeCnt;i++){
				if(pCakeArray[i-1] > pCakeArray[i]){
					return false;
				}
			}
			return true;
		}
		
		void Init(int* pCakeArray,int nCakeCnt){
			m_nCakeCnt = nCakeCnt;
			m_CakeArray = new int[m_nCakeCnt];
			for(int i=0;i<m_nCakeCnt;i++){
				m_CakeArray[i] = pCakeArray[i];
			}
			m_ReverseCakeArray = new int[m_nCakeCnt];
			for(int i=0;i<m_nCakeCnt;i++){
				m_ReverseCakeArray[i] = m_CakeArray[i];
			}
			
			
			m_nMaxSwap = 2*m_nCakeCnt;
			m_SwapArray = new int[m_nMaxSwap+1];
			m_ReverseCakeArraySwap = new int[m_nMaxSwap];
		}
		
		int LowerBound(int* pCakeArray,int nCakeCnt){
			int t,ret = 0;
			for(int i=1;i<nCakeCnt;i++){
				t = pCakeArray[i] - pCakeArray[i-1];
				if(t==1||t==-1){
					
				}else{
					ret++;
				}
			}
			return ret;
		}
		
		void Run(int* pCakeArray,int nCakeCnt){
			Init(pCakeArray,nCakeCnt);
			m_nSearch = 0;
			Search(0);
		}
		
		void Output(){
			for(int i=0;i<m_nMaxSwap;i++){
				cout << m_SwapArray[i] << " ";
			}
			cout << endl;
			cout <<"|Search times| " << m_nSearch << endl;
			cout << "|Swap times| " << m_nMaxSwap <<endl; 
		}
		
		
	private:
		int* m_CakeArray;
		int m_nCakeCnt;
		int* m_ReverseCakeArray;
		int* m_ReverseCakeArraySwap;
		int* m_SwapArray;
		int m_nMaxSwap;
		int m_nSearch;
}; 


int main(){
	Solution s;
	
	int a[] = {3,2,1,6,5,4,9,8,7,0};
	s.Run(a,10);
	s.Output();
}
