#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FamilyEditWindow : public System::Windows::Forms::Form
	{
	public:
		FamilyEditWindow(Family& family) : family(family)
		{
			InitializeComponent();
		}

	protected:
		~FamilyEditWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container ^components;
		System::Windows::Forms::TextBox^ familyName;
		System::Windows::Forms::Panel^ parentsPanel;
		System::Windows::Forms::Label^ fatherLabel;
		System::Windows::Forms::Label^ motherLabel;
		System::Windows::Forms::Button^ editFatherButton;
		System::Windows::Forms::Button^ editMotherButton;
	private: System::Windows::Forms::Label^ childrenLabel;
	private: System::Windows::Forms::Label^ petsLabel;

		Family& family;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void);

#pragma endregion
	};
}
