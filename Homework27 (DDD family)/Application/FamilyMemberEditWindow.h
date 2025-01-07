#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FamilyMemberEditWindow : public System::Windows::Forms::Form
	{
	public:
		FamilyMemberEditWindow(Family& family, FamilyMember familyMember)
			: family(family), familyMember(&familyMember)
		{
			InitializeComponent();
		}

	protected:
		~FamilyMemberEditWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::TextBox^ nameTextBox;
		System::Windows::Forms::TextBox^ surnameTextBox;

		System::Windows::Forms::NumericUpDown^ day;
		System::Windows::Forms::Label^ birthDateLabel;
		System::Windows::Forms::NumericUpDown^ month;
		System::Windows::Forms::NumericUpDown^ year;

		System::Windows::Forms::TextBox^ phoneNumberTextBox;
		System::Windows::Forms::Label^ phoneNumberLabel;

		System::Windows::Forms::Label^ genderLabel;
		System::Windows::Forms::TextBox^ genderTextBox;

		System::Windows::Forms::Label^ nationalityLabel;
		System::Windows::Forms::TextBox^ nationalityTextBox;
	 
		System::ComponentModel::Container ^components;

		Family& family;
		FamilyMember* familyMember;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void);

#pragma endregion
	private: System::Void name_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
