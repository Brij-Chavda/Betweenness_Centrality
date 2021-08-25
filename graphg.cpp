#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <iostream>
#include <fstream>
#include <string>

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS> Graph;
typedef boost::sorted_erdos_renyi_iterator<boost::mt19937, Graph> ERGen;
typedef boost::graph_traits<Graph>::edge_iterator edge_iterator;
typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;


void randGraphGen(int n, float Pedge, char* f)
{
	
	std::ofstream fileOut;
//	boost::minstd_rand gen;
	boost::mt19937 gen;
	
/*	nodeNum = std::__cxx11::stoi(argv[1]);
	edgeProb = std::__cxx11::stof(argv[2]);*/
	Graph g(ERGen(gen,n,Pedge),ERGen(),n);
	
	IndexMap index = boost::get(boost::vertex_index,g);
	edge_iterator  ei, ei_end;
	std::tie (ei, ei_end) = edges(g);
	
	fileOut.open(f);
	
	while(ei != ei_end){
		fileOut << index[source(*ei,g)] + 1 << ' ' << index[target(*ei,g)] + 1 << " 1" << std::endl;
		++ei;
	}
	
	fileOut.close();
	return;
}

int main()
{	
	int n;
	float Pedge;
	char *f;
	std::cout << "Enter number of nodes";
	std::cin >> n;
	std::cout << "Enter Probability";
	std::cin >> Pedge;
	std::cout << "Enter Filename";
	std::cin >> *f;
	randGraphGen(n,Pedge,f);
	return 0;	
}
