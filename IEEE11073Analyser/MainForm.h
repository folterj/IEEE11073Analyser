#pragma once

#include "nomenclature.h"
#include "phd_types.h"
#include "ntp.h"
#include "IEEEBuffer.h"
#include "TreeStore.h"
#include "AboutForm.h"
#include "conversion.h"

namespace IEEE11073Analyser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Summary for MainForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TreeView^  treeView;
	private: System::Windows::Forms::RichTextBox^  dataText;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::GroupBox^  dataGroup;
	private: System::Windows::Forms::Panel^  outputPanel;
	private: System::Windows::Forms::GroupBox^  treeGroup;
	private: System::Windows::Forms::GroupBox^  messageGroup;
	private: System::Windows::Forms::RichTextBox^  messageText;
	private: System::Windows::Forms::Splitter^  splitter1;
	private: System::Windows::Forms::Splitter^  splitter2;
	private: System::Windows::Forms::ToolStrip^  menuToolStrip;
	private: System::Windows::Forms::ToolStripButton^  processButton;
	private: System::Windows::Forms::ToolStripButton^  expandButton;
	private: System::Windows::Forms::ToolStripButton^  collapseButton;
	private: System::Windows::Forms::ToolStripButton^  clearButton;
	private: System::Windows::Forms::ToolStripButton^  aboutButton;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  selectAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;

	private:
		IEEEBuffer buffer;
		TreeStore store;
		AboutForm aboutForm;
		int height0;
		float dataFrac, messageFrac, treeFrac;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->treeView = (gcnew System::Windows::Forms::TreeView());
			this->contextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->selectAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataText = (gcnew System::Windows::Forms::RichTextBox());
			this->dataGroup = (gcnew System::Windows::Forms::GroupBox());
			this->outputPanel = (gcnew System::Windows::Forms::Panel());
			this->treeGroup = (gcnew System::Windows::Forms::GroupBox());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->messageGroup = (gcnew System::Windows::Forms::GroupBox());
			this->messageText = (gcnew System::Windows::Forms::RichTextBox());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->menuToolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->processButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->clearButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->expandButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->collapseButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->aboutButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->contextMenu->SuspendLayout();
			this->dataGroup->SuspendLayout();
			this->outputPanel->SuspendLayout();
			this->treeGroup->SuspendLayout();
			this->messageGroup->SuspendLayout();
			this->menuToolStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeView
			// 
			this->treeView->ContextMenuStrip = this->contextMenu;
			this->treeView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView->Location = System::Drawing::Point(3, 16);
			this->treeView->Name = L"treeView";
			this->treeView->Size = System::Drawing::Size(618, 289);
			this->treeView->TabIndex = 0;
			this->treeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainForm::mainTreeView_AfterSelect);
			// 
			// contextMenu
			// 
			this->contextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->selectAllToolStripMenuItem, 
				this->copyToolStripMenuItem});
			this->contextMenu->Name = L"contextMenuStrip";
			this->contextMenu->Size = System::Drawing::Size(165, 48);
			// 
			// selectAllToolStripMenuItem
			// 
			this->selectAllToolStripMenuItem->Name = L"selectAllToolStripMenuItem";
			this->selectAllToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->selectAllToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->selectAllToolStripMenuItem->Text = L"Select &All";
			this->selectAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::selectAllToolStripMenuItem_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copyToolStripMenuItem.Image")));
			this->copyToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->copyToolStripMenuItem->Text = L"&Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::copyToolStripMenuItem_Click);
			// 
			// dataText
			// 
			this->dataText->ContextMenuStrip = this->contextMenu;
			this->dataText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataText->EnableAutoDragDrop = true;
			this->dataText->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dataText->Location = System::Drawing::Point(3, 16);
			this->dataText->Name = L"dataText";
			this->dataText->Size = System::Drawing::Size(618, 77);
			this->dataText->TabIndex = 0;
			this->dataText->Text = L"";
			this->dataText->Enter += gcnew System::EventHandler(this, &MainForm::inputText_Enter);
			// 
			// dataGroup
			// 
			this->dataGroup->Controls->Add(this->dataText);
			this->dataGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->dataGroup->Location = System::Drawing::Point(0, 0);
			this->dataGroup->Name = L"dataGroup";
			this->dataGroup->Size = System::Drawing::Size(624, 96);
			this->dataGroup->TabIndex = 0;
			this->dataGroup->TabStop = false;
			this->dataGroup->Text = L"Data";
			// 
			// outputPanel
			// 
			this->outputPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->outputPanel->Controls->Add(this->treeGroup);
			this->outputPanel->Controls->Add(this->splitter1);
			this->outputPanel->Controls->Add(this->messageGroup);
			this->outputPanel->Controls->Add(this->splitter2);
			this->outputPanel->Controls->Add(this->dataGroup);
			this->outputPanel->Location = System::Drawing::Point(0, 42);
			this->outputPanel->Name = L"outputPanel";
			this->outputPanel->Size = System::Drawing::Size(624, 520);
			this->outputPanel->TabIndex = 8;
			this->outputPanel->Resize += gcnew System::EventHandler(this, &MainForm::outputPanel_Resize);
			// 
			// treeGroup
			// 
			this->treeGroup->Controls->Add(this->treeView);
			this->treeGroup->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeGroup->Location = System::Drawing::Point(0, 212);
			this->treeGroup->Name = L"treeGroup";
			this->treeGroup->Size = System::Drawing::Size(624, 308);
			this->treeGroup->TabIndex = 4;
			this->treeGroup->TabStop = false;
			this->treeGroup->Text = L"Message Tree";
			// 
			// splitter1
			// 
			this->splitter1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->splitter1->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter1->Location = System::Drawing::Point(0, 204);
			this->splitter1->MinExtra = 100;
			this->splitter1->MinSize = 100;
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(624, 8);
			this->splitter1->TabIndex = 3;
			this->splitter1->TabStop = false;
			this->splitter1->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &MainForm::splitter1_SplitterMoved);
			// 
			// messageGroup
			// 
			this->messageGroup->Controls->Add(this->messageText);
			this->messageGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->messageGroup->Location = System::Drawing::Point(0, 104);
			this->messageGroup->Name = L"messageGroup";
			this->messageGroup->Size = System::Drawing::Size(624, 100);
			this->messageGroup->TabIndex = 2;
			this->messageGroup->TabStop = false;
			this->messageGroup->Text = L"Message";
			// 
			// messageText
			// 
			this->messageText->BackColor = System::Drawing::Color::White;
			this->messageText->ContextMenuStrip = this->contextMenu;
			this->messageText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messageText->EnableAutoDragDrop = true;
			this->messageText->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->messageText->Location = System::Drawing::Point(3, 16);
			this->messageText->Name = L"messageText";
			this->messageText->ReadOnly = true;
			this->messageText->Size = System::Drawing::Size(618, 81);
			this->messageText->TabIndex = 0;
			this->messageText->Text = L"";
			// 
			// splitter2
			// 
			this->splitter2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->splitter2->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitter2->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter2->Location = System::Drawing::Point(0, 96);
			this->splitter2->MinExtra = 100;
			this->splitter2->MinSize = 100;
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(624, 8);
			this->splitter2->TabIndex = 1;
			this->splitter2->TabStop = false;
			this->splitter2->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &MainForm::splitter2_SplitterMoved);
			// 
			// menuToolStrip
			// 
			this->menuToolStrip->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuToolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->processButton, 
				this->clearButton, this->expandButton, this->collapseButton, this->aboutButton});
			this->menuToolStrip->Location = System::Drawing::Point(0, 0);
			this->menuToolStrip->Name = L"menuToolStrip";
			this->menuToolStrip->Size = System::Drawing::Size(624, 39);
			this->menuToolStrip->TabIndex = 0;
			// 
			// processButton
			// 
			this->processButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->processButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"processButton.Image")));
			this->processButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->processButton->Name = L"processButton";
			this->processButton->Size = System::Drawing::Size(36, 36);
			this->processButton->Text = L"Process";
			this->processButton->Click += gcnew System::EventHandler(this, &MainForm::processButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->clearButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"clearButton.Image")));
			this->clearButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(36, 36);
			this->clearButton->Text = L"Clear";
			this->clearButton->Click += gcnew System::EventHandler(this, &MainForm::clearButton_Click);
			// 
			// expandButton
			// 
			this->expandButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->expandButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"expandButton.Image")));
			this->expandButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->expandButton->Name = L"expandButton";
			this->expandButton->Size = System::Drawing::Size(36, 36);
			this->expandButton->Text = L"Expand All";
			this->expandButton->Click += gcnew System::EventHandler(this, &MainForm::expandButton_Click);
			// 
			// collapseButton
			// 
			this->collapseButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->collapseButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"collapseButton.Image")));
			this->collapseButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->collapseButton->Name = L"collapseButton";
			this->collapseButton->Size = System::Drawing::Size(36, 36);
			this->collapseButton->Text = L"Collapse All";
			this->collapseButton->Click += gcnew System::EventHandler(this, &MainForm::collapseButton_Click);
			// 
			// aboutButton
			// 
			this->aboutButton->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->aboutButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->aboutButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"aboutButton.Image")));
			this->aboutButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->aboutButton->Name = L"aboutButton";
			this->aboutButton->Size = System::Drawing::Size(36, 36);
			this->aboutButton->Text = L"About";
			this->aboutButton->Click += gcnew System::EventHandler(this, &MainForm::aboutButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 562);
			this->Controls->Add(this->menuToolStrip);
			this->Controls->Add(this->outputPanel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"IEEE 11073 Analyser";
			this->contextMenu->ResumeLayout(false);
			this->dataGroup->ResumeLayout(false);
			this->outputPanel->ResumeLayout(false);
			this->treeGroup->ResumeLayout(false);
			this->messageGroup->ResumeLayout(false);
			this->menuToolStrip->ResumeLayout(false);
			this->menuToolStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		MainForm(void) {
			InitializeComponent();

			height0 = 0;
			dataFrac = 0.2f;
			messageFrac = 0.2f;
			treeFrac = 0.6f;
			resizeOutputPanel();
		}

	protected:
		~MainForm() {
			if (components) {
				delete components;
			}
		}

	private:

		void process() {
			buffer.reset();
			store.clear();
			treeView->Nodes->Clear();

			parseString(dataText->Text);
			dataText->Text = bufferToString();

			while (buffer.pointer < buffer.size()) {
				processAPDU(buffer.size()*2);
			}

			messageText->Text = store.createTreeString();

			treeView->Nodes->AddRange(store.createTreeNodes());
			treeView->ExpandAll();
		}

		void parseString(String^ s) {
			array<String^>^ vals;
			array<Char>^ seps = {',',' ','\t','\n','\r'};
			String^ val;
			Byte xh,xl,x;

			vals = s->Split(seps,StringSplitOptions::RemoveEmptyEntries);
			for (int i=0;i<vals->Length;) {
				val = vals[i++]->Trim();
				if (val->ToLower()->StartsWith("0x")) {
					// remove hex identifier
					val = val->Substring(2);
				}
				if (val->Length > 2) {
					Byte::TryParse(val->Substring(0,2),NumberStyles::AllowHexSpecifier,CultureInfo::InvariantCulture,xh);
					Byte::TryParse(val->Substring(2),NumberStyles::AllowHexSpecifier,CultureInfo::InvariantCulture,xl);
					buffer.push_back(0x100*xh + xl);
				} else {
					Byte::TryParse(val,NumberStyles::AllowHexSpecifier,CultureInfo::InvariantCulture,x);
					if (i % 2 != 0) {
						xh = x;
					} else {
						xl = x;
						buffer.push_back((UInt16)0x100*xh + xl);
					}
				}
			}
		}

		String^ bufferToString() {
			String^ s = "";
			for (int i=0;i<buffer.size();i++) {
				s+= String::Format("{0:X4} ",buffer[i]);
			}
			return s;
		}

		bool checkEndLen(int end) {
			return (buffer.pointer == end);
		}

		int endLen(int len) {
			int len2 = len/2;
			return buffer.pointer + len2;
		}

		Node^ addNode(TreeStore^ tree,String^ label,String^ content,int pointer) {
			return tree->add(label,content,pointer,buffer.pointer);
		}

		Node^ addNode(TreeStore^ tree,String^ label,int content,int pointer) {
			return tree->add(label,content.ToString(),pointer,buffer.pointer);
		}

		Node^ addNode(TreeStore^ tree,String^ label,String^ content,int pointer,Color color) {
			return tree->add(label,content,pointer,buffer.pointer,color);
		}

		Node^ addNode(TreeStore^ tree,String^ label,int content,int pointer,Color color) {
			return tree->add(label,content.ToString(),pointer,buffer.pointer,color);
		}

		Node^ addNode(TreeStore^ tree,String^ label,TreeStore^ children,int pointer) {
			return tree->add(label,children,pointer,buffer.pointer);
		}

		void processAPDU(int maxlen) {
			int p = buffer.pointer;
			addNode(%store,"ACSE",processACSE(maxlen),p);
		}

		TreeStore^ processACSE(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			int p = buffer.pointer;
			int choice = buffer.next();
			addNode(tree,"APDU CHOICE Type",apduChoice(choice),p,Color::Blue);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"CHOICE.Length",len,p);
			int len2;
			Node^ node2;
			if (buffer.checkLen(len,maxlen)) {
				p = buffer.pointer;
				switch (choice) {
					case AARQ_CHOSEN:
						addNode(tree,"Association Request",processAARQ(len),p);
						break;
					case AARE_CHOSEN:
						addNode(tree,"Association Response",processAARE(len),p);
						break;
					case RLRQ_CHOSEN:
						addNode(tree,"Association Release Request",processReleaseReason(len),p);
						break;
					case RLRE_CHOSEN:
						addNode(tree,"Association Release Response",processReleaseReason(len),p);
						break;
					case ABRT_CHOSEN:
						addNode(tree,"Abort",processAbortReason(len),p);
						break;
					case PRST_CHOSEN:
						len2 = buffer.next();
						node2 = addNode(tree,"OCTET STRING.Length",len2,p);
						if (buffer.checkLen(len2,maxlen)) {
							buffer.resetRelPointer();
							p = buffer.pointer;
							int invokeId = buffer.next();
							addNode(tree,"Invoke ID",invokeId,p);
							p = buffer.pointer;
							addNode(tree,"ROSE",processROSE(len2),p);
						} else {
							node2->color = Color::Red;
							buffer.skipUpto(maxlen);
						}
						break;
					default:
						buffer.skipUpto(len);
						addNode(tree,"?","",p);
						break;
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processReleaseReason(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			int reason = buffer.next();
			int p = buffer.pointer;
			addNode(tree,"Reason",releaseReason(reason),p);
			return tree;
		}

		TreeStore^ processAbortReason(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			int reason = buffer.next();
			int p = buffer.pointer;
			addNode(tree,"Reason",abortReason(reason),p);
			return tree;
		}

		TreeStore^ processROSE(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int choice2 = buffer.next();
			bool invoke = ((choice2 & 0x0100) > 0);
			addNode(tree,"CHOICE",acseChoice(choice2),p,Color::Blue);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"CHOICE.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				buffer.resetRelPointer();
				p = buffer.pointer;
				switch (choice2) {
					case ROIV_CMIP_EVENT_REPORT_CHOSEN:
					case ROIV_CMIP_CONFIRMED_EVENT_REPORT_CHOSEN:
					case RORS_CMIP_CONFIRMED_EVENT_REPORT_CHOSEN:
						addNode(tree,"CMISE",processCMISE(invoke,len),p);
						break;
					case ROIV_CMIP_GET_CHOSEN:
						addNode(tree,"CMISE",processGet(len),p);
						break;
					case RORS_CMIP_GET_CHOSEN:
						addNode(tree,"MDS Attributes",processAttrs(false,len),p);
						break;
					case ROER_CHOSEN:
						addNode(tree,"Error",processError(len),p);
						break;
					case RORJ_CHOSEN:
						addNode(tree,"Reject",processReject(len),p);
						break;
					case ROIV_CMIP_CONFIRMED_ACTION_CHOSEN:
						addNode(tree,"Action",processAction(len),p);
						break;
					case RORS_CMIP_CONFIRMED_ACTION_CHOSEN:
						addNode(tree,"Action",processActionResponse(len),p);
						break;
					default:
						buffer.skipUpto(len);
						addNode(tree,"?","",p);
						break;
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processCMISE(bool invoke,int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int handle = buffer.next();
			addNode(tree,"Handle",handle,p);
			p = buffer.pointer;
			addNode(tree,"Event-Time",buffer.nextTime(),p);
			p = buffer.pointer;
			int eventType = buffer.next();
			addNode(tree,"Event-Type",roseChoice(eventType),p,Color::Blue);
			p = buffer.pointer;
			int len = buffer.next();
			IEEERegion^ region = buffer.getRegion(len);
			Node^ node = addNode(tree,"Event-Info.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				p = buffer.pointer;
				switch (eventType) {
					case MDC_NOTI_CONFIG:
						if (invoke)
							addNode(tree,"Config Request",processConf(len),p);
						else
							addNode(tree,"Config Response",processConfResp(len),p);
						break;
					case MDC_NOTI_SCAN_REPORT_FIXED:
					case MDC_NOTI_SCAN_REPORT_MP_FIXED:
					case MDC_NOTI_BUF_SCAN_REPORT_FIXED:
					case MDC_NOTI_BUF_SCAN_REPORT_MP_VAR:
						addNode(tree,"Report",processReportFixed(len),p);
						break;
					case MDC_NOTI_SCAN_REPORT_VAR:
					case MDC_NOTI_SCAN_REPORT_MP_VAR:
					case MDC_NOTI_BUF_SCAN_REPORT_VAR:
					case MDC_NOTI_BUF_SCAN_REPORT_MP_FIXED:
						addNode(tree,"Report",processReportVar(len),p);
						break;
					case MDC_NOTI_BUF_SCAN_REPORT_GROUPED:
					case MDC_NOTI_BUF_SCAN_REPORT_MP_GROUPED:
						break;
					default:
						buffer.skipUpto(len);
						addNode(tree,"?","",p);
						break;
				}
				if (!buffer.checkRegionEnd(region)) {
					node->color = Color::Red;
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processError(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			String^ s = "";
			int p = buffer.pointer;
			int error = buffer.next();
			addNode(tree,"Error",errorId(error),p,Color::Blue);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				p = buffer.pointer;
				s = buffer.nextBytes(len);
				addNode(tree,"Value",s,p);
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processReject(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int problem = buffer.next();
			addNode(tree,"Problem",rejectId(problem),p,Color::Blue);
			return tree;
		}

		TreeStore^ processAction(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int handle = buffer.next();
			addNode(tree,"Handle",handle,p);
			p = buffer.pointer;
			int type = buffer.next();
			addNode(tree,"Type",actionType(type),p,Color::Blue);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				p = buffer.pointer;
				switch (type) {
					case MDC_ACT_SET_TIME:
						addNode(tree,"AbsTime",processSetAbsTime(len),p);
						break;
					case MDC_ACT_SET_BO_TIME:
						addNode(tree,"BOTime",processSetBOTime(len),p);
						break;
					default:
						buffer.skipUpto(len);
						addNode(tree,"?","",p);
						break;
				}
			} else {
				node->color = Color::Red;
			}
			return tree;
		}

		TreeStore^ processActionResponse(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int handle = buffer.next();
			addNode(tree,"Handle",handle,p);
			p = buffer.pointer;
			int type = buffer.next();
			addNode(tree,"Type",actionType(type),p,Color::Blue);
			p = buffer.pointer;
			int result = buffer.next();
			String^ results;
			if (result == 0) {
				results = "Ok";
			} else {
				results = errorId(result);
			}
			addNode(tree,"Result",results,p);
			return tree;
		}

		TreeStore^ processSetAbsTime(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			String^ time = buffer.nextAbsTime();
			addNode(tree,"Time",time,p);
			p = buffer.pointer;
			int accuracy = buffer.next();
			addNode(tree,"Accuracy",accuracy,p);
			return tree;
		}

		TreeStore^ processSetBOTime(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			String^ time = buffer.nextBOTime();
			addNode(tree,"Time",time,p);
			p = buffer.pointer;
			int accuracy = buffer.next();
			addNode(tree,"Accuracy",accuracy,p);
			return tree;
		}

		TreeStore^ processAARQ(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int assocver = (int)buffer.next(4);
			addNode(tree,"Assoc-Version",String::Format("{0:X8}",assocver),p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Data-Proto-List.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Data-Proto-List.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int i=0;i<n;i++) {
					p = buffer.pointer;
					addNode(tree,"Proto",processProtos(len),p);
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processAARE(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int result = buffer.next();
			addNode(tree,"Result",assocRes(result),p,Color::Blue);
			p = buffer.pointer;
			addNode(tree,"Proto",processProtos(maxlen),p);
			return tree;
		}

		TreeStore^ processProtos(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int id = buffer.next();
			String^ s;
			addNode(tree,"Data-Proto-ID",id,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Data-Proto-Info.Length",len,p);
			IEEERegion^ region = buffer.getRegion(len);
			if (buffer.checkLen(len,maxlen)) {
				p = buffer.pointer;
				int ver = (int)buffer.next(4);
				addNode(tree,"Proto.Version",String::Format("{0:X8}",ver),p);
				p = buffer.pointer;
				int enc = buffer.next();
				s = "";
				if (enc & ASN1_MDER)
					s+= "MDER ";
				if (enc & ASN1_XER)
					s+= "XER ";
				if (enc & ASN1_PER)
					s+= "PER ";
				addNode(tree,"Encoding rules",s,p);
				p = buffer.pointer;
				int nomver = (int)buffer.next(4);
				addNode(tree,"Nomenclature Version",String::Format("{0:X8}",nomver),p);
				p = buffer.pointer;
				int funcunits = (int)buffer.next(4);
				addNode(tree,"Functional Units",String::Format("{0:X8}",funcunits),p);
				p = buffer.pointer;
				int systype = (int)buffer.next(4);
				s = "";
				if (systype & SYS_TYPE_MANAGER)
					s+= "Manager ";
				if (systype & SYS_TYPE_AGENT) {
					s+= "Agent ";
				}
				addNode(tree,"System Type",s,p,Color::Blue);
				p = buffer.pointer;
				int len2 = buffer.next();
				addNode(tree,"System-ID.Length",len2,p);
				p = buffer.pointer;
				s = buffer.nextBytes(len2);
				addNode(tree,"System-ID",s,p);
				p = buffer.pointer;
				int configid = buffer.next();
				if (systype & SYS_TYPE_AGENT)
					addNode(tree,"Dev-Config-ID",configId(configid),p,Color::Blue);
				else
					addNode(tree,"Dev-Config-ID",configId(configid),p);
				p = buffer.pointer;
				int modeFlags = buffer.next();
				addNode(tree,"Data-Req-Mode-Flags",String::Format("{0:X4}",modeFlags),p);
				p = buffer.pointer;
				int initCount = buffer.next();
				addNode(tree,"Data-Req-Agent/Manager-Init-Count",String::Format("{0:X4}",initCount),p);
				p = buffer.pointer;
				int listn = buffer.next();
				addNode(tree,"Option-List-Count",listn,p);
				p = buffer.pointer;
				int listlen = buffer.next();
				addNode(tree,"Option-List-Length",listlen,p);
				p = buffer.pointer;
				s = buffer.nextBytes(listlen);
				if (listlen > 0)
					addNode(tree,"Option-List",s,p);
				if (!buffer.checkRegionEnd(region))
					node->color = Color::Red;
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processGet(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int handle = buffer.next();
			addNode(tree,"Handle",handle,p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Attribute-Id-List.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Attribute-Id-List.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int i=0;i<n;i++) {
					//addNode(tree,buffer.pointer,"Proto",);
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processConf(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int reportid = buffer.next();
			addNode(tree,"Config-Report-ID",String::Format("{0:X4}",reportid),p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Config-Obj-List.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Config-Obj-List.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int j=0;j<n;j++) {
					p = buffer.pointer;
					addNode(tree,"Object Attributes",processAttrs(true,len),p);
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processConfResp(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int reportid = buffer.next();
			addNode(tree,"ConfigReportRsp.Config-Report-ID",String::Format("{0:X4}",reportid),p);
			p = buffer.pointer;
			int result = buffer.next();
			addNode(tree,"ConfigReportRsp.Config-Result",resultId(result),p);
			return tree;
		}

		TreeStore^ processAttrs(bool config,int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			IEEERegion^ region = buffer.getRegion(maxlen);
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int nodei = 0;
			if (config) {
				int objclass = buffer.next();
				addNode(tree,"Obj-Class",objClass(objclass),p);
				p = buffer.pointer;
			}
			int handle = buffer.next();
			addNode(tree,"Obj-Handle",handle,p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Attributes.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Attributes.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int j=0;j<n && !buffer.eof();j++) {
					p = buffer.pointer;
					addNode(tree,"Attribute",processAttr(len),p);
					if (buffer.popError()) {
						buffer.skipRegion(region);
						break;
					}
				}
			} else {
				node->color = Color::Red;
				buffer.skipRegion(region);
			}
			return tree;
		}

		TreeStore^ processAttr(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			UInt16 part,type;
			int len2;
			int p = buffer.pointer;
			String^ s = "";
			int attrid = buffer.next();
			addNode(tree,"Attribute-Id",attrId(attrid),p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"Attribute-Value.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {	// comparison not very useful
				p = buffer.pointer;
				switch (attrid) {
					case MDC_ATTR_ATTRIBUTE_VAL_MAP:
						addNode(tree,"Val Map",processMap(len),p);
						break;
					case MDC_ATTR_ID_PHYSIO_LIST:
						addNode(tree,"Physio List",processList(len),p);
						break;
					case MDC_ATTR_SYS_TYPE_SPEC_LIST:
						addNode(tree,"TypeVerList",processTypeVerList(len),p);
						break;
					case MDC_ATTR_ID_TYPE:
						part = buffer.next();
						type = buffer.next();
						s = String::Format("{0} : {1}",partId(part),typeId(type));
						break;
					case MDC_ATTR_UNIT_CODE:
						type = buffer.next();
						s = String::Format("{0}",unitId(type));
						break;
					case MDC_ATTR_DEV_CONFIG_ID:
						type = buffer.next();
						s = String::Format("{0}",configId(type));
						break;
					case MDC_ATTR_SYS_ID:
						len2 = buffer.next();
						addNode(tree,"Octet.String.Length",len2,p);
						p = buffer.pointer;
						s = buffer.nextString(len2);
						addNode(tree,"String",s,p);
						s = "";
						break;
					case MDC_ATTR_ID_MODEL:
						len2 = buffer.next();
						addNode(tree,"Octet.String.Length",len2,p);
						p = buffer.pointer;
						s = buffer.nextString(len2);
						addNode(tree,"String",s,p);
						p = buffer.pointer;
						len2 = buffer.next();
						addNode(tree,"Octet.String.Length",len2,p);
						p = buffer.pointer;
						s = buffer.nextString(len2);
						addNode(tree,"String",s,p);
						s = "";
						break;
					case MDC_ATTR_TIME_ABS:
						s = buffer.nextAbsTime();
						break;
					case MDC_ATTR_TIME_BO:
						s = buffer.nextBOTime();
						break;
					default:
						s = buffer.nextBytes(len);
						break;
				}
				if (s != "") {
					addNode(tree,"",s,p);
				}
			} else {
				node->color = Color::Red;
			}
			return tree;
		}

		TreeStore^ processMap(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			String^ s = "";
			int n = buffer.next();
			addNode(tree,"AttrValMap.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"AttrValMap.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int i=0;i<n && !buffer.eof();i++) {
					p = buffer.pointer;
					int attrid = buffer.next();
					int len2 = buffer.next();
					addNode(tree,attrId(attrid),String::Format("Length: {0}",len2),p);
				}
			} else {
				node->color = Color::Red;
			}
			return tree;
		}

		TreeStore^ processList(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			String^ s = "";
			int n = buffer.next();
			addNode(tree,"MetricIdList.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"MetricIdList.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int i=0;i<n && !buffer.eof();i++) {
					p = buffer.pointer;
					int attrid = buffer.next();
					addNode(tree,typeId(attrid),"",p);
				}
			} else {
				node->color = Color::Red;
			}
			return tree;
		}

		TreeStore^ processTypeVerList(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			String^ s = "";
			int n = buffer.next();
			addNode(tree,"TypeVerList.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			Node^ node = addNode(tree,"TypeVerList.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int i=0;i<n && !buffer.eof();i++) {
					p = buffer.pointer;
					int type = buffer.next();
					addNode(tree,"Type",devtypeId(type),p,Color::Blue);
					p = buffer.pointer;
					int ver = buffer.next();
					addNode(tree,"Version",ver,p);
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processReportFixed(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int reportid = buffer.next();
			addNode(tree,"Scan-Req-ID",String::Format("{0:X4}",reportid),p);
			p = buffer.pointer;
			int reportno = buffer.next();
			addNode(tree,"Scan-Report-No",reportno,p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Obs-Scan-Fixed.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			IEEERegion^ region = buffer.getRegion(len);
			Node^ node = addNode(tree,"Obs-Scan-Fixed.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int j=0;j<n && !buffer.eof();j++) {
					p = buffer.pointer;
					addNode(tree,"Obs-Scan-Fixed",processReportObs(len),p);
					if (buffer.popError()) {
						buffer.skipRegion(region);
						break;
					}
				}
				if (!buffer.checkRegionEnd(region)) {
					node->color = Color::Red;
				}
			} else {
				node->color = Color::Red;
				buffer.skipRegion(region);
			}
			return tree;
		}

		TreeStore^ processReportVar(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			int p = buffer.pointer;
			int reportid = buffer.next();
			addNode(tree,"Scan-Req-ID",String::Format("{0:X4}",reportid),p);
			p = buffer.pointer;
			int reportno = buffer.next();
			addNode(tree,"Scan-Report-No",reportno,p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Scan-Var.Count",n,p);
			p = buffer.pointer;
			int len = buffer.next();
			IEEERegion^ region = buffer.getRegion(len);
			Node^ node = addNode(tree,"Scan-Var.Length",len,p);
			if (buffer.checkLen(len,maxlen)) {
				for (int j=0;j<n && !buffer.eof();j++) {
					p = buffer.pointer;
					addNode(tree,"Scan-Var",processReportObsVar(len),p);
					if (buffer.popError()) {
						buffer.skipRegion(region);
						break;
					}
				}
				if (!buffer.checkRegionEnd(region)) {
					node->color = Color::Red;
				}
			} else {
				node->color = Color::Red;
				buffer.skipRegion(region);
			}
			return tree;
		}

		TreeStore^ processReportObs(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			String^ s = "";
			int p = buffer.pointer;
			int objHandle = buffer.next();
			addNode(tree,"Obj-Handle",objHandle,p);
			p = buffer.pointer;
			int len2 = buffer.next();
			Node^ node = addNode(tree,"Obs-Val-Data.Length",len2,p);
			if (buffer.checkLen(len2,maxlen)) {
				p = buffer.pointer;
				s = buffer.nextBytes(len2);
				addNode(tree,s,"",p);
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		TreeStore^ processReportObsVar(int maxlen) {
			TreeStore^ tree = gcnew TreeStore();
			buffer.resetRelPointer();
			String^ s = "";
			int p = buffer.pointer;
			int objHandle = buffer.next();
			addNode(tree,"Obj-Handle",objHandle,p);
			p = buffer.pointer;
			int n = buffer.next();
			addNode(tree,"Val-Data.Count",n,p);
			p = buffer.pointer;
			int len2 = buffer.next();
			Node^ node = addNode(tree,"Val-Data.Length",len2,p);
			if (buffer.checkLen(len2,maxlen)) {
				for (int j=0;j<n && !buffer.eof();j++) {
					p = buffer.pointer;
					addNode(tree,"Attr",processAttr(len2),p);
				}
			} else {
				node->color = Color::Red;
				buffer.skipUpto(maxlen);
			}
			return tree;
		}

		System::Void processButton_Click(System::Object^  sender, System::EventArgs^  e) {
			process();
		}

		System::Void expandButton_Click(System::Object^  sender, System::EventArgs^  e) {
			treeView->ExpandAll();
		}

		System::Void collapseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			treeView->CollapseAll();
		}

		System::Void mainTreeView_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
			Node^ node = store.findNode(e->Node->Name);
			int startindex = node->startindex;
			int endindex = node->endindex;
			// reset colour
			dataText->SelectAll();
			dataText->SelectionColor = dataText->ForeColor;
			if (startindex >= 0 && endindex > startindex) {
				// set selection colour
				dataText->Select(startindex*5,(endindex-startindex)*5);
				dataText->SelectionColor = Color::Red;
				dataText->ScrollToCaret();
			}
		}

		System::Void inputText_Enter(System::Object^  sender, System::EventArgs^  e) {
			dataText->SelectAll();
			dataText->SelectionColor = dataText->ForeColor;
		}

		System::Void selectAllToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Control^ control = getControl(sender);
			if (control) {
				if (control == dataText) {
					dataText->SelectAll();
				}
				if (control == messageText) {
					messageText->SelectAll();
				}
			}
		}

		System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Control^ control = getControl(sender);
			if (control) {
				if (control == dataText) {
					dataText->Copy();
				}
				if (control == messageText) {
					messageText->Copy();
				}
				if (control == treeView) {
					Clipboard::SetText(treeView->SelectedNode->Text);
				}
			}
		}

		Control^ getControl(Object^ sender)
		{
			// get menu source control
			ToolStripDropDownItem^ item = (ToolStripDropDownItem^)sender;
			System::Windows::Forms::ContextMenuStrip^ menu = (System::Windows::Forms::ContextMenuStrip^)item->Owner;
			Control^ control = menu->SourceControl;
			if (control == nullptr)
			{
				// if null; get currently active control
				control = ActiveControl;
			}
			return control;
		}

		void clearAll() {
			buffer.clear();
			store.clear();
			dataText->Clear();
			messageText->Clear();
			treeView->Nodes->Clear();
		}

		System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
			clearAll();
		}

		System::Void aboutButton_Click(System::Object^  sender, System::EventArgs^  e) {
			aboutForm.ShowDialog();
		}

		void updateFracs() {
			dataFrac = (float)dataGroup->Height / height0;
			messageFrac = (float)messageGroup->Height / height0;
			treeFrac = (float)treeGroup->Height / height0;
		}

		void resizeOutputPanel() {
			int height = outputPanel->ClientSize.Height - splitter1->Height - splitter2->Height;
			if (height != height0) {
				dataGroup->Height = (int)(dataFrac * height);
				messageGroup->Height = (int)(messageFrac * height);
				treeGroup->Height = (int)(treeFrac * height);
				height0 = height;
			}
		}

		System::Void splitter1_SplitterMoved(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) {
			updateFracs();
		}

		System::Void splitter2_SplitterMoved(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) {
			updateFracs();
		}

		System::Void outputPanel_Resize(System::Object^  sender, System::EventArgs^  e) {
			resizeOutputPanel();
		}

	};
}
