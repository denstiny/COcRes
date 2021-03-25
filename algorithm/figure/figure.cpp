#include "./Cmap.hpp"
#include <iostream>
using namespace std;
int main(int argc, char**argv)
{

	CMap *pMap = new CMap(6);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	pMap->setValueToMatrixForUndirectedGraph(0, 1, 7);
	pMap->setValueToMatrixForUndirectedGraph(0, 2, 1);
	pMap->setValueToMatrixForUndirectedGraph(0, 3, 9);
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 2);
	pMap->setValueToMatrixForUndirectedGraph(1, 4, 3);
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 11);
	pMap->setValueToMatrixForUndirectedGraph(2, 4, 8);
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 4);
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 5);
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 15);

	cout << "打印矩阵: " << endl;
	pMap->printMatrix();
	cout << endl;

	pMap->resetNode();

	cout << "深度优先遍历: " << endl;
	pMap->depthFirstTraverse(0);
	cout << endl;

	pMap->resetNode();

	cout << "广度优先遍历: " << endl;
	pMap->breadthFirstTraverse(0);
	cout << endl;

	pMap->resetNode();

	cout << "普里姆算法: " << endl;
	pMap->primTree(0);
	cout << endl;

	pMap->resetNode();

	cout << "克鲁斯卡尔算法: " << endl;
	pMap->kruskalTree();
	cout << endl;

	pMap->resetNode();

	system("pause");
	return 0;
}
