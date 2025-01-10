#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuWindow : public System::Windows::Forms::Form
	{
	public:
		MenuWindow(void)
		{
			InitializeComponent();
		}

	protected:
		~MenuWindow()
		{
			DataSaver* dataSaver = DataSaver::getInstance(*this->saveFolder);
			dataSaver->deleteOldSavings();

			for (const auto& family : *this->families)
				dataSaver->save(family, family.getId());

			delete this->saveFolder;

			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ addFamilyButton;
		System::Windows::Forms::Panel^ familyPanel;
		System::ComponentModel::Container ^components;
		std::vector<Family>* families;
		std::string* saveFolder;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);

		void AddFamily(Panel^ panel, const json& serializedObject);
#pragma endregion

	private: System::Void MenuWindow_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	private: System::Void AddFamilyButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void RemoveButtonClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void EditButtonClick(System::Object^ sender, System::EventArgs^ e);

	};
}
