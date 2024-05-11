//---------------------------------------------------------------------------

#include <fmx.h>
#include<queue>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
class Question{
public:
	char* Text;
	char* Answer1;
	char* Answer2;
	char* Answer3;
	char* Answer4;
	int CorrectAnswer;

	Question(){}
	Question(char* text, char* ans1, char* ans2, char* ans3, char* ans4, int correctAns){
		Text=text;
		Answer1=ans1;
		Answer2=ans2;
		Answer3=ans3;
		Answer4=ans4;

		CorrectAnswer=correctAns;
	}

};

std::queue<Question> LoadQuestions(){
	Question q1=Question("What is smallest unit of the information?","Bit","Byte","Block","nibble",1);
	Question q2=Question("Which of the following is an output device?","Keyboard","Mouse","Light pen","VDU",4);
	Question q3=Question("The central processing unit is located in the _____.","Hard disk","System unit","Memory unit","Monitor",2);
	Question q4=Question("What is the speed of computer measured in?","Nanoseconds","Kilo-seconds","Gigahertz","Megabytes",3);
	Question q5=Question(" Which of the following numbers is a binary number?","1 and 2","0 and 0.1","2 and 0","0 and 1",4);
	std::queue<Question> questions;
	questions.push(q1);
	questions.push(q2);
	questions.push(q3);
	questions.push(q4);
	questions.push(q5);

	return questions;
}

std::queue<Question>  questions;
Question currentQuestion;
int selectedAnswer;    //to know which answer user selected we declare a global variable
int points=0;          //zero points before starting


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)   // we write code inside it as this form is the design interface we made
{
	questions=LoadQuestions();
	currentQuestion=questions.front();       //means put questions at front to currentQuestion

	Question->Text= currentQuestion.Text;
	Answer1->Text= currentQuestion.Answer1;
	Answer2->Text= currentQuestion.Answer2;
	Answer3->Text= currentQuestion.Answer3;
    Answer4->Text= currentQuestion.Answer4;

	questions.pop();                   // by this we remove the queestion that we already have showed to the user
	Point->Text=points;          //when we start quiz it shows initial point value
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer1Change(TObject *Sender)   // these below answer1,2,3radiobutton,confirmbutton  are event handler to handle when person click on them
{   //this is created to know what will happen after answer is invoked
	selectedAnswer=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer2Change(TObject *Sender)
{
	selectedAnswer=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer3Change(TObject *Sender)
{
	selectedAnswer=3;
}
void __fastcall TForm1::Answer4Change(TObject *Sender)
{
	selectedAnswer=4;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmClick(TObject *Sender)
{
   if(selectedAnswer==currentQuestion.CorrectAnswer) {
	  points++;
	  Point->Text=points;    //it update points after clicking answer
   }

   if(!questions.empty()){        // if question is there in the queue or ended
	  currentQuestion=questions.front();

	  Question->Text= currentQuestion.Text;
	  Answer1->Text= currentQuestion.Answer1;
	  Answer2->Text= currentQuestion.Answer2;
	  Answer3->Text= currentQuestion.Answer3;
	  Answer4->Text= currentQuestion.Answer4;

	  questions.pop();      //remove the question after answered

	  Answer1->IsChecked=false;    //to deselect the answer when go to next question
	  Answer2->IsChecked=false;
	  Answer3->IsChecked=false;
	  Answer4->IsChecked=false;
   }
   else{
	 Confirm->Enabled=false;     //disable confirm button if no more question in the queue
	 Confirm->Text="Quiz Completed";
   }
}

//---------------------------------------------------------------------------

