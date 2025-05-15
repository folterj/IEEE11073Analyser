#pragma once

#include <cliext/vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace cliext;


ref class Node
{
public:
	String^ label;
	String^ content;
	int startindex,endindex;
	Color color;
	vector<Node^>^ children;

	Node();
	Node(String^ label0,String^ content0,int startindex0,int endindex0);
	Node(String^ label0,String^ content0,int startindex0,int endindex0,Color color0);
	Node(String^ label0,vector<Node^>^ children0,int startindex0,int endindex0);
	String^ getText();
	String^ getImportantText();
};


ref class TreeStore : public vector<Node^>
{
public:
	TreeStore();
	Node^ add(String^ label,String^ content,int startindex,int endindex);
	Node^ add(String^ label,String^ content,int startindex,int endindex,Color color);
	Node^ add(String^ label,TreeStore^ children,int startindex,int endindex);
	Node^ findNode(String^ hierarchy);
	array<TreeNode^>^ createTreeNodes();
	static array<TreeNode^>^ createTreeNodes(vector<Node^>^ nodes,String^ hierarchy0);
	String^ createTreeString();
	String^ createTreeString(vector<Node^>^ nodes);
};
