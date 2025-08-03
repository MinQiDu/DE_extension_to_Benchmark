@echo off
cd /d "C:\Users\user\Documents\MyCode\VisualStudio\meta_algo\jade\x64\Release"

:: 共用參數
set dim=30
set pop_size=100
set mCR=0.5
set mF=0.5
set c=0.1
set p=0.05
set archive=1

:: ========== f1 ==========
echo Running f1 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %c% %p% 1 %archive%

:: ========== f2 ==========
echo Running f2 with iter = 2000
jade.exe 2000 %dim% %pop_size% %mCR% %mF% %c% %p% 2 %archive%

:: ========== f3 ==========
echo Running f3 with iter = 5000
jade.exe 5000 %dim% %pop_size% %mCR% %mF% %c% %p% 3 %archive%

:: ========== f4 ==========
echo Running f4 with iter = 5000
jade.exe 5000 %dim% %pop_size% %mCR% %mF% %c% %p% 4 %archive%

:: ========== f5 ==========
echo Running f5 with iter = 3000
jade.exe 3000 %dim% %pop_size% %mCR% %mF% %c% %p% 5 %archive%
echo Running f5 with iter = 20000
jade.exe 20000 %dim% %pop_size% %mCR% %mF% %c% %p% 5 %archive%

:: ========== f6 ==========
echo Running f6 with iter = 100
jade.exe 100 %dim% %pop_size% %mCR% %mF% %c% %p% 6 %archive%
echo Running f6 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %c% %p% 6 %archive%

:: ========== f7 ==========
echo Running f7 with iter = 3000
jade.exe 3000 %dim% %pop_size% %mCR% %mF% %c% %p% 7 %archive%

:: ========== f8 ==========
echo Running f8 with iter = 1000
jade.exe 1000 %dim% %pop_size% %mCR% %mF% %c% 0.2 8 %archive%
echo Running f8 with iter = 9000
jade.exe 9000 %dim% %pop_size% %mCR% %mF% %c% 0.2 8 %archive%

:: ========== f9 ==========
echo Running f9 with iter = 1000
jade.exe 1000 %dim% %pop_size% %mCR% %mF% %c% %p% 9 %archive%
echo Running f9 with iter = 5000
jade.exe 5000 %dim% %pop_size% %mCR% %mF% %c% %p% 9 %archive%

:: ========== f10 ==========
echo Running f10 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %c% %p% 10 %archive%
echo Running f10 with iter = 2000
jade.exe 2000 %dim% %pop_size% %mCR% %mF% %c% %p% 10 %archive%

:: ========== f11 ==========
echo Running f11 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %c% %p% 11 %archive%
echo Running f11 with iter = 3000
jade.exe 3000 %dim% %pop_size% %mCR% %mF% %c% %p% 11 %archive%

:: ========== f12 ==========
echo Running f12 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %c% %p% 12 %archive%
echo Running f12 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %c% %p% 12 %archive%

:: ========== f13 ==========
echo Running f13 with iter = 500
jade.exe 500 %dim% %pop_size% %mCR% %mF% %c% %p% 13 %archive%
echo Running f13 with iter = 1500
jade.exe 1500 %dim% %pop_size% %mCR% %mF% %c% %p% 13 %archive%

pause
