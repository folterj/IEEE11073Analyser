#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Reflection;


namespace IEEE11073Analyser {

	/// <summary>
	/// Summary for AboutForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  productLabel;
	private: System::Windows::Forms::PictureBox^  logoPicture;
	private: System::Windows::Forms::Label^  versionLabel;
	private: System::Windows::Forms::Label^  compLabel;
	private: System::Windows::Forms::RichTextBox^  descText;
	private: System::Windows::Forms::Label^  copyLabel;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->productLabel = (gcnew System::Windows::Forms::Label());
			this->logoPicture = (gcnew System::Windows::Forms::PictureBox());
			this->copyLabel = (gcnew System::Windows::Forms::Label());
			this->versionLabel = (gcnew System::Windows::Forms::Label());
			this->compLabel = (gcnew System::Windows::Forms::Label());
			this->descText = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// productLabel
			// 
			this->productLabel->AutoSize = true;
			this->productLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->productLabel->Location = System::Drawing::Point(138, 12);
			this->productLabel->Name = L"productLabel";
			this->productLabel->Size = System::Drawing::Size(64, 20);
			this->productLabel->TabIndex = 0;
			this->productLabel->Text = L"Product";
			this->productLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// logoPicture
			// 
			this->logoPicture->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPicture.Image")));
			this->logoPicture->Location = System::Drawing::Point(12, 12);
			this->logoPicture->Name = L"logoPicture";
			this->logoPicture->Size = System::Drawing::Size(120, 120);
			this->logoPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->logoPicture->TabIndex = 2;
			this->logoPicture->TabStop = false;
			// 
			// copyLabel
			// 
			this->copyLabel->AutoSize = true;
			this->copyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->copyLabel->Location = System::Drawing::Point(138, 76);
			this->copyLabel->Name = L"copyLabel";
			this->copyLabel->Size = System::Drawing::Size(76, 20);
			this->copyLabel->TabIndex = 3;
			this->copyLabel->Text = L"Copyright";
			this->copyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// versionLabel
			// 
			this->versionLabel->AutoSize = true;
			this->versionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->versionLabel->Location = System::Drawing::Point(138, 45);
			this->versionLabel->Name = L"versionLabel";
			this->versionLabel->Size = System::Drawing::Size(63, 20);
			this->versionLabel->TabIndex = 4;
			this->versionLabel->Text = L"Version";
			this->versionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// compLabel
			// 
			this->compLabel->AutoSize = true;
			this->compLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->compLabel->Location = System::Drawing::Point(138, 112);
			this->compLabel->Name = L"compLabel";
			this->compLabel->Size = System::Drawing::Size(76, 20);
			this->compLabel->TabIndex = 5;
			this->compLabel->Text = L"Company";
			this->compLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// descText
			// 
			this->descText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->descText->Location = System::Drawing::Point(12, 138);
			this->descText->Name = L"descText";
			this->descText->ReadOnly = true;
			this->descText->Size = System::Drawing::Size(302, 46);
			this->descText->TabIndex = 6;
			this->descText->Text = L"";
			this->descText->LinkClicked += gcnew System::Windows::Forms::LinkClickedEventHandler(this, &AboutForm::descText_LinkClicked);
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 196);
			this->Controls->Add(this->descText);
			this->Controls->Add(this->versionLabel);
			this->Controls->Add(this->copyLabel);
			this->Controls->Add(this->logoPicture);
			this->Controls->Add(this->productLabel);
			this->Controls->Add(this->compLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"About";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPicture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		AboutForm(void)
		{
			InitializeComponent();

			Assembly^ assembly = Assembly::GetExecutingAssembly();
			AssemblyName^ assemblyName = assembly->GetName();
			String^ name = assemblyName->Name;
			String^ version = assemblyName->Version->ToString();
			String^ copyright = ((AssemblyCopyrightAttribute^)assembly->GetCustomAttributes(AssemblyCopyrightAttribute::typeid,false)[0])->Copyright;
			String^ company = ((AssemblyCompanyAttribute^)assembly->GetCustomAttributes(AssemblyCompanyAttribute::typeid,false)[0])->Company;
			String^ desc = ((AssemblyDescriptionAttribute^)assembly->GetCustomAttributes(AssemblyDescriptionAttribute::typeid,false)[0])->Description;

			Text = "About " + name;
			productLabel->Text = name;
			versionLabel->Text = "Version " + version;
			compLabel->Text = company;
			copyLabel->Text = copyright;
			descText->Text = desc;
		}

	protected:
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Void descText_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkClickedEventArgs^  e) {
			System::Diagnostics::Process::Start(e->LinkText);
		}

	};
}
