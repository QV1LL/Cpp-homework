#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PetEditWindow : public System::Windows::Forms::Form
	{
	public:
		PetEditWindow(Pet& familyMember)
			: pet(&familyMember)
		{
			InitializeComponent();
		}

	protected:
		~PetEditWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private:

		System::Windows::Forms::TextBox^ nameTextBox;

		System::Windows::Forms::Label^ birthDateLabel;
		System::Windows::Forms::NumericUpDown^ day;
		System::Windows::Forms::NumericUpDown^ month;
		System::Windows::Forms::NumericUpDown^ year;

		System::Windows::Forms::Label^ petTypeLabel;
		System::Windows::Forms::TextBox^ petTypeTextBox;

		System::Windows::Forms::Label^ weightLabel;
		System::Windows::Forms::TextBox^ weight;

		System::ComponentModel::Container^ components;

		Pet* pet;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void);

#pragma endregion

	private:
		System::Void onTextChanged(System::Object^ sender, System::EventArgs^ e);

	};
}
