fp:	main.o Control.o Record.o ReportGenerator.o Report1.o Report2.o Report3.o View.o
	g++ -o fp main.o Control.o Record.o ReportGenerator.o Report1.o Report2.o Report3.o View.o

main.o:	main.cc Control.h Record.h Map.h ReportData.h ReportGenerator.h
	g++ -c main.cc

Control.o: Control.cc Control.h Record.h Map.h ReportGenerator.h CompareBehaviour.h AscBehaviour.h Report1.h DescBehaviour.h Report2.h Report3.h View.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Map.h Record.h
	g++ -c ReportGenerator.cc

Report1.o: Report1.cc Report1.h ReportData.h CompareBehaviour.h ReportGenerator.h AscBehaviour.h DescBehaviour.h
	g++ -c Report1.cc

Report2.o: Report2.cc Report2.h ReportData.h CompareBehaviour.h ReportGenerator.h AscBehaviour.h DescBehaviour.h
	g++ -c Report2.cc

Report3.o: Report3.cc Report1.h ReportData.h CompareBehaviour.h ReportGenerator.h AscBehaviour.h DescBehaviour.h
	g++ -c Report3.cc

clean:
	rm -f *.o fp
