@echo off
cd /d "C:\Users\user\Documents\MyCode\VisualStudio\meta_algo\jade\x64\Release"

:: 共用參數
set dim=30
set pop_size=100
set mCR=0.5
set mF=0.5
set H=100
set p=0.05
set archive=1
set algo=SHADE

:: ========== f1 ==========
echo Running f1 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %H% %p% 1 %archive% "%algo%"

:: ========== f2 ==========
echo Running f2 with iter = 2000
jade.exe 2000 %dim% %pop_size% %mCR% %mF% %H% %p% 2 %archive% "%algo%"

:: ========== f3 ==========
echo Running f3 with iter = 5000
jade.exe 5000 %dim% %pop_size% %mCR% %mF% %H% %p% 3 %archive% "%algo%"

:: ========== f4 ==========
echo Running f4 with iter = 5000
jade.exe 5000 %dim% %pop_size% %mCR% %mF% %H% %p% 4 %archive% "%algo%"

:: ========== f5 ==========
echo Running f5 with iter = 3000
jade.exe 3000 %dim% %pop_size% %mCR% %mF% %H% %p% 5 %archive% "%algo%"
echo Running f5 with iter = 20000
jade.exe 20000 %dim% %pop_size% %mCR% %mF% %H% %p% 5 %archive% "%algo%"

:: ========== f6 ==========
echo Running f6 with iter = 100
jade.exe 100 %dim% %pop_size% %mCR% %mF% %H% %p% 6 %archive% "%algo%"
echo Running f6 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %H% %p% 6 %archive% "%algo%"

:: ========== f7 ==========
echo Running f7 with iter = 3000
jade.exe 3000 %dim% %pop_size% %mCR% %mF% %H% %p% 7 %archive% "%algo%"

:: ========== f8 ==========
echo Running f8 with iter = 1000
jade.exe 1000 %dim% %pop_size% %mCR% %mF% %H% 0.2 8 %archive% "%algo%"
echo Running f8 with iter = 9000
jade.exe 9000 %dim% %pop_size% %mCR% %mF% %H% 0.2 8 %archive% "%algo%"

:: ========== f9 ==========
echo Running f9 with iter = 1000
jade.exe 1000 %dim% %pop_size% %mCR% %mF% %H% %p% 9 %archive% "%algo%"
echo Running f9 with iter = 5000
jade.exe 5000 %dim% %pop_size% %mCR% %mF% %H% %p% 9 %archive% "%algo%"

:: ========== f10 ==========
echo Running f10 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %H% %p% 10 %archive% "%algo%"
echo Running f10 with iter = 2000
jade.exe 2000 %dim% %pop_size% %mCR% %mF% %H% %p% 10 %archive% "%algo%"

:: ========== f11 ==========
echo Running f11 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %H% %p% 11 %archive% "%algo%"
echo Running f11 with iter = 3000
jade.exe 3000 %dim% %pop_size% %mCR% %mF% %H% %p% 11 %archive% "%algo%"

:: ========== f12 ==========
echo Running f12 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %H% %p% 12 %archive% "%algo%"
echo Running f12 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %H% %p% 12 %archive% "%algo%"

:: ========== f13 ==========
echo Running f13 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %H% %p% 13 %archive% "%algo%"
echo Running f13 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %H% %p% 13 %archive% "%algo%"

pause
