//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Question;
	TRadioButton *Answer1;
	TRadioButton *Answer2;
	TRadioButton *Answer3;
	TButton *Confirm;
	TLabel *Label2;
	TLabel *Point;
	TRadioButton *Answer4;
	void __fastcall Answer1Change(TObject *Sender);
	void __fastcall Answer2Change(TObject *Sender);
	void __fastcall Answer3Change(TObject *Sender);
	void __fastcall ConfirmClick(TObject *Sender);
	void __fastcall Answer4Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
