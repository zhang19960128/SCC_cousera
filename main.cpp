#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
/*status 0(white) represent not visited, 1(gray) represent visited but not finished DFS search tree not stopped,2(Black) represents DFS search tree stoped */
/*f map the original node ----> magic order*/
/*g map the magic order -----> original node*/
void DFS_v_mark(std::vector<std::list<int> > &graph,std::vector<int>& status,std::vector<int>& f,std::vector<int>& g,int node,int& times){
	status[node]=1;
	for(std::list<int>::iterator a=graph[node].begin();a!=graph[node].end();a++){
		if(status[*a]==0){
	 		DFS_v_mark(graph,status,f,g,*a,times);
		}
	}
	status[node]=2;
	f[node]=times;
        g[times]=node;
	times=times+1;
}
void DFS(std::vector<std::list<int> >& graph,std::vector<int>& status,std::vector<int>& f,std::vector<int>& g){
	int times=1;
	size_t size=status.size();
	for(size_t i=1;i<size;i++){
		status[i]=0;
                f[i]=0;
                g[i]=0;
	}
	for(size_t i=1;i<size;i++){
		if(status[i]==0){
			DFS_v_mark(graph,status,f,g,i,times);
		}
	}
}
void DFS_v(std::vector<std::list<int> > &graph,std::list<int> &vlist,std::vector<int>& status,int node){
      status[node]=1;
      for(std::list<int>::iterator a=graph[node].begin();a!=graph[node].end();a++){
         if(status[*a]==0){
            DFS_v(graph,vlist,status,*a);
            vlist.push_back(*a);
         }
      }
}
void SCC(std::vector<std::list<int> >& graph,std::vector<std::list<int> >& gcc_graph,std::vector<int>& f,std::vector<int>& g){
      size_t size=g.size();
      std::vector<int> status(size,0);
      for(size_t i=size-1;i>=1;i++){
         if(status[i]==0){

         }
      }
}
int main(){
	std::fstream fs;
	fs.open("scc.txt",std::fstream::in);
	std::vector<std::list<int> > graph;
	graph.push_back(std::list<int>(0,0));
	int one,two;
	one=1;
	while(fs>>one){
		fs>>two;
		if(one>=graph.size()){
			for(size_t i=graph.size();i<=one;i++){
				graph.push_back(std::list<int>(0,0));
			}
			graph[one].push_back(two);
		}
		else{
			graph[one].push_back(two);
		}
	}
	std::vector<std::list<int> > graph_re(graph.size(),std::list<int>(0,0));
	int i=graph.size();
	for(size_t j=0;j<i;j++)
		for(std::list<int>::iterator k=graph[j].begin();k!=graph[j].end();k++){
			graph_re[*k].push_back(j);
		}
	std::cout<<"reverse succeed!"<<std::endl;
	std::vector<int> status(i,0);
	std::vector<int> f(i,0);
        std::vector<int> g(i,0);
	DFS(graph_re,status,f,g);//compute the magic order.

}
