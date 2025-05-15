#include "StdAfx.h"
#include "TreeStore.h"

using namespace System::Globalization;


Node::Node() {
	label = "";
	content = "";
	startindex = 0;
	endindex = 0;
	color = Color::Black;
}

Node::Node(String^ label0,String^ content0,int startindex0,int endindex0) {
	label = label0;
	content = content0;
	startindex = startindex0;
	endindex = endindex0;
	color = Color::Black;
}

Node::Node(String^ label0,String^ content0,int startindex0,int endindex0,Color color0) {
	label = label0;
	content = content0;
	startindex = startindex0;
	endindex = endindex0;
	color = color0;
}

Node::Node(String^ label0,vector<Node^>^ children0,int startindex0,int endindex0) {
	label = label0;
	content = "";
	startindex = startindex0;
	endindex = endindex0;
	children = children0;
	color = Color::Black;
}

String^ Node::getText() {
	String^ s;

	s = label;
	if (label != "" && content != "")
		s += ":";
	s += content;
	return s;
}

String^ Node::getImportantText() {
	int out;
	String^ content0 = content->Trim();

	if (content0 == "") {
		return label;
	} else if (!int::TryParse(content0,NumberStyles::AllowHexSpecifier,CultureInfo::InvariantCulture,out)) {
		// not a (hex) number
		return content;
	}
	return "";
}


TreeStore::TreeStore() {
	// don't initialise children; avoid infinite creation loop
}

Node^ TreeStore::add(String^ label,String^ content,int startindex,int endindex) {
	Node^ node = gcnew Node(label,content,startindex,endindex);
	push_back(node);
	return node;
}

Node^ TreeStore::add(String^ label,String^ content,int startindex,int endindex,Color color) {
	Node^ node = gcnew Node(label,content,startindex,endindex,color);
	push_back(node);
	return node;
}

Node^ TreeStore::add(String^ label,TreeStore^ children,int startindex,int endindex) {
	Node^ node = gcnew Node(label,children,startindex,endindex);
	push_back(node);
	return node;
}

Node^ TreeStore::findNode(String^ hierarchy) {
	vector<Node^>^ nodes = this;
	Node^ node;
	array<String^>^ h = hierarchy->Split('.');
	int i;

	for (int l=0;l<h->Length;l++) {
		i = int::Parse(h[l]);
		node = nodes[i];
		if (l < h->Length-1)
			nodes = node->children;
	}
	return node;
}

array<TreeNode^>^ TreeStore::createTreeNodes() {
	return createTreeNodes(this,"");
}

array<TreeNode^>^ TreeStore::createTreeNodes(vector<Node^>^ nodes,String^ hierarchy0) {
	array<TreeNode^>^ treenodes;
	Node^ node;
	String^ s;
	String^ hierarchy;

	treenodes = gcnew array<TreeNode^>(nodes->size());
	for (int i=0;i<nodes->size();i++) {
		node = nodes[i];

		hierarchy = hierarchy0;
		if (hierarchy0 != "")
			hierarchy+= ".";
		hierarchy+= String::Format("{0}",i);

		s = node->getText();
		if (node->children) {
			treenodes[i] = gcnew TreeNode(s,TreeStore::createTreeNodes(node->children,hierarchy));
		} else {
			treenodes[i] = gcnew TreeNode(s);
		}
		treenodes[i]->Name = hierarchy;
		treenodes[i]->ForeColor = node->color;
	}
	return treenodes;
}

String^ TreeStore::createTreeString() {
	return createTreeString(this);
}

String^ TreeStore::createTreeString(vector<Node^>^ nodes) {
	String^ treestring = "";
	String^ s;
	Node^ node;

	for (int i=0;i<nodes->size();i++) {
		node = nodes[i];
		s = node->getImportantText();
		if (treestring != "" && s != "") {
			treestring += ",";
		}
		treestring += s;
		if (node->children) {
			s = TreeStore::createTreeString(node->children);
			if (s != ""){
				treestring += "{" + s + "}";
			}
		}
	}
	
	return treestring;
}
