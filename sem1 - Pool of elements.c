                      /* Pool of Elements ( The modern periodic table ) */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i,j,n,k,count=0,y,n1=0,n2=0,t,q;
char zero[1][3]={"0"},zero1[1][3]={"0*"},zero2[1][5]={"0**"},zero3[1][7]={"0***"};
void Element_info(char[][3]),Element_info_periodic_properties();
void periodic_properties(),Ionization_Energy(),compounds();
void checking(float[],char[][3],int),iso();
void printorder(char[][7],float[],int);
void trends(float[]);
void electronic_configeration(int);
int main()
{  // Periodic Table printing
 char At_No[118][3]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nb","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
printf("\t\t                   ' POOL OF ELEMENTS ' \n");
printf("\t\t                                        - The Modern Peridic Table ");
printf("\n\n");
	printf("\t\t    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18\n\n");
	printf("\t\t  'S block'                                 'P block'    \n\n");
	printf("\t\t1 - H                                                  He\n");
	printf("\t\t2 - Li Ne           'D block'           B  C  N  O  F  Ne\n");
	printf("\t\t3 - Na Mg                               Al Si P  S  Cl Ar\n");
	printf("\t\t4 - K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr\n");
	printf("\t\t5 - Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I  Xe\n");
	printf("\t\t6 - Cs Ba    Hf Ta W  Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn\n");
	printf("\t\t7 - Fr Ra    Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og\n\n");
    printf("\t  'F block'\t  La Ce Pr Nb Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu\n");
    printf("\t           \t  Ac Th pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr\n");
		// periodic table printing completed
 do
  {
  	printf("\n\n\n");
  		int v;        // choise selection varible
	printf("\t1)Element informantion and Periodic Properties\n\t2)Compounds of Different atoms\n\t3)Exit\n\n  Enter displayed choices : ");
	scanf("%d",&v);
	printf("\n");
	switch(v)
	{
		case 1 :  	Element_info_periodic_properties(At_No);
		             break;
		case 2 :    compounds(At_No);
		             break;
		case 3 :     printf("\n\n                                        -> Thank You <-\n");
		             exit(1);
					 break;
		default :    printf("\tEnter displayed choices only !!!\n");			         
					              
	}
	printf("\n\t1)To Execute again\n\t2)To Exit\n\n  Enter displayed choices :  ");
	scanf("%d",&q);	

  }while(q!=2);
  if(q==2){ 	
  printf("\n\n                        * Hoping that you have learned something new about Elements and its properties * \n");
  printf("\n\n                                                      -> Thank You <-\n"); }
}
void Element_info_periodic_properties(char At_No[][3])
{
     int f; // choise selection varible
	printf("\t1)To Know the information of Element\n\t2)To Know about trends in periodic properties\n\t3)Istopes , Isobars , Isotones , Isodiaphers\n\t4)Exit\n\n  Enter displayed choices : ");
	 scanf("%d",&f);
	 printf("\n");
	 switch(f)
	 {
	 	case 1 : Element_info(At_No);
	 	         break;
	 	case 2 : periodic_properties();
		         break;
	    case 3 : iso(At_No);
		         break;
		case 4 : printf("\n\n                                 -> Thank You <-\n");   
		         exit(0);
				 break;      
		default :   printf("\n  Eneter displayed choices only\n");			 			          
	 }	 
}
void Element_info(char At_No[][3])
{
  int e,o;
  char num[119][5]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100","101","102","103","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118"};
  char y[1][25],ch[1][50],num1[1][20];
  char valencies[118][100]={"1,-1","0","1,-1","2","3,2,1","4,3,2,1,-1,-2,-4","4,3,2,1,0,-1,-2,-3","2,1,0,-1,-2","-1","0","1,-1","2","3,1","4,3,2,1,0,-1,-2,-3","5,4,3,2,1,0,-1,-2,-3","6,5,4,3,2,1,0,-1,-2","6,5,4,3,2,1,0,-1,-2","0","1,-1","2","3,2,1","4,3,2,0,-1,-2","5,4,3,2,1,0,-1,-2","6,5,4,3,2,1,-1,-2,-3,-4","7,6,5,4,3,2,1,0,-1,-2,-3","6,5,4,3,2,1,0,-1,-2","5,4,3,2,1,0,-1","6,4,3,2,1,0,-1","4,3,2,1,0","2,1,0","3,2,1","4,3,2,1","5,3,2,-3","6,4,2,1,-2","7,5,4,3,1,0,-1","2,0","1,-1","2","3,2","4,3,2,1,0","5,4,3,2,1,0,-1,-3","6,5,4,3,2,1,0,-1,-2","7,6,5,4,3,2,1,0,-1,-3","8,7,6,5,4,3,2,1,0,-2","6,5,4,3,2,1,0,-1","4,2,0","3,2,1,0","2,1","3,2,1","4,2,-4","5,3,-3","6,5,4,3,2,1,-2","7,5,3,1,0,-1","8,6,4,3,2,0","1,-1","2","3,2","4,3,2","4,3,2","4,3,2","3","3,2","3,2","3,2,1","4,3,1","4,3,2","3,2","3","3,2","3,2","3","4,3,2,1","5,4,3,2,1,-1,-3","6,5,4,3,2,1,0,-1,-2,-4","7,6,5,4,3,2,1,0,-1,-3","8,7,6,5,4,3,2,1,0,-2","6,5,4,3,2,1,0,-1","6,5,4,3,2,0","7,5,3,2,10,-1","2,1","3,1","4,2","5,3,1,-3","6,4,2,-2","7,5,3,1,-1","2,0","1","2","3","4,3,2","5,4,3","6,5,4,3,2","7,6,5,4,3,2","7,6,5,4,3,2","7,6,5,4,3,2","6,5,4,3,2","4,3,2","5,4,3,2","4,3,2","4,3,2","3,2,1","3,2","3,2","4,3","5,4","6,5,4","7,6,5,4,3","8,7,4,3,2","6,5,4,3,2,1","6,5,4,3,2,1","3,-1","2,1","1","2","3,1","4,2","Unknown","8,6,4,3,2"};
  char Name[118][25]={"Hydrogen","Helium","Lithium","Berrilium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon","Sodium","Magnesium","Alluminium","Silicon","Phosphorus","Sulphur","Chlorines","Argon","Pottasium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickle","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technesium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine","Xenon","Caesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promrthium","Samarium","Europium","Gadolinium","Terbium","Dysoprosium","Holmium","Erbium","Thulium","Ytterbium","Lutetium","Hafnium","Tantalum","Tungesten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon","Framcium","Radium","Actinium","Thorium","Protactium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copermicium","Nihonium","Flerovium","Moscovium","Livermorium","Tennessine","Oganesson"};    
  float weights[118]={1.008,4.0026,6.94,9.0122,10.81,12.011,14.007,15.999,18.998,20.180,22.990,24.305,26.982,28.085,30.974,32.06,35.45,39.948,39.098,40.078,44.956,47.867,50.942,51.996,54.938,55.845,58.933,58.693,63.546,65.38,69.723,72.630,74.922,78.971,79.904,83.798,85.468,87.62,88.906,91.224,92.906,95.95,98,101.07,102.91,106.42,107.87,112.41,114.82,118.71,121.76,127.60,126.90,131.29,132.91,137.91,138.91,140.12,140.91,144.24,145,150.36,151.96,157.25,158.93,162.50,164.93,167.26,168.93,173.05,174.97,178.49,180.95,183.84,186.21,190.23,192.22,195.08,196.97,200.59,204.38,207.2,208.98,209,210,222,223,226,227,232.04,231.04,238.03,237,244,243,247,247,251,252,257,258,259,266,267,268,269,270,277,278,281,282,285,286,289,290,293,294,294};

    printf("\t1)By Atomic Symbol \n\t2)By Atomic Number \n\t3)By Element Name\n\n  Enter the type you need : ");
  	    scanf("%d",&o);
  	    printf("\n");
	   if(o==1)
       {
             	printf("  Enter Elemet Symbol : ");
             	scanf("%s",y[0]);
            	printf("\n");
            	count=0;
    for(i=0;i<118;i++)
       {   
         	  if(strcmp(At_No[i],y[0])==0)
         	   	   {
         	   	   	   e=i+1;
         	   	   	   break;
				   }
				   count++;
        }
         	    if(count==118)
         	       {
         	       	printf("  Enter existing elements only !!");
         	           goto loop;
			       }	
        }
		 else if (o==2)
	   {
		 	printf("  Enter Atomic number : ");
		 	scanf("%d",&e);
		 	printf("\n");
		 	if(e>118)
		   {
		 		printf("  Enter Existing Elements only !!");
		 		goto loop;
		   }

	    }
		 else if (o==3)
		   {
		    printf("  Enter Elemet Name like the 1st letter must be upper case : ");
         	scanf("%s",y[0]);
         	printf("\n");
         	   count=0;
         	   for(i=0;i<118;i++)
         	   {   
         	        count=count+1;
         	   	   if(strcmp(Name[i],y[0])==0)
         	   	   {
         	   	   	   e=i+1;//Atomic Number which is used to print all the other properties
         	   	   	   break;
				   }
		       }
         	    if(count==118)
         	       {
         	       	printf("  Enter existing elements only !!");
         	           goto loop;
				   }  
         	
		   } 
		   else
		   {
		   		printf("\n  Enter Displayed choices only !!");
		   goto loop;
		   }
  
    printf("\tElement Symbol                : %s \n",At_No[e-1]); 
    printf("\tElement Name                  : %s \n",Name[e-1]);
    printf("\tElement Atomic Number         : %d \n",e);
  	 printf("\tElement Atomic weight         : %.3fg/mol\n",weights[e-1]);
  	 printf("\tPossible Valencies are        : %s\n",valencies[e-1]);
     printf("\tElectronic Configeration is   :"); 
    electronic_configeration(e);
    loop : 	printf("\n\n                                 -> Thank You <-\n");
}
void electronic_configeration(int e)
{
	FILE *fp;
  char num[119][5]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100","101","102","103","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118"};
  char t[1][20],ch[1][100],num1[1][20];
	fp=fopen("compounds.txt","r");
		while(!feof(fp))
	{
		fscanf(fp,"%s",t[0]);
		if(strcmp(num[e-1],t[0])==0)
		{
		fscanf(fp,"%[^\n]",ch[0]);
    	printf("%s\n",ch[0]);	
    	break;
		}
		
	 }
char ch1[strlen(ch[0]) + 1];
	 strcpy(ch1,ch[0]);
     printf("\t'%c' block element",ch1[strlen(ch[0]) - 2] - 32);
	 fclose(fp);
}

 // Element information complated.
 //periodic properties starts
 void compounds()
 {
 	
char At_No[118][3]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nb","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};	
 		FILE *fp;
		    fp=fopen("compounds.txt","r");
	char x[4][20],y[20],test[0][100],compoundname[0][50];
	int  m[20],notfound;
	char mole[16][3]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
scan :	printf("  User can enter only 2-3 atoms only\n  Enter Number of Atoms the molecule contains  : ");
	scanf("%d",&n);
	if(n>3)
	   {
	   	printf("\n  You Entered more that specified number of atoms !! \n\n");
	   goto scan;
	   }
	   else if(n<=0)
	   {
	   		printf("\n  You Entered more that specified number of atoms !! \n\n");
	   goto scan;
	   }
	else  
	printf("\n  Enter Cation first and enter Anion\n");
	for(i=0;i<n;i++)
	{
		printf("\n  Number of moles of %d Element : ",i+1);
		scanf("%d",&m[i]);
		printf("  Enter %d Elements symbol      : ",i+1);
	enter :	scanf("%s",x[i]);
		 for(j=0;j<118;j++)
		 {
		 	count++;
		 	if(strcmp(At_No[j],x[i])==0){ break; }
		 }
		 if(j==118)
		 {
		 	printf("  Element does not found\n  Enter again                  : ");
		 	goto enter;
		 }
		 else
		 continue;
		 printf("\n");
	}
for(i=0;i<=n-1;i++)
{
	if(n==2 && i==1 && m[i]==1){ break; }	
	if(m[i]==1)
		 	strcat(x[0],x[i+1]);
		else 
		{
			strcat(x[0],mole[m[i]-1]);
		if(i!=n-1)	{
			strcat(x[0],x[i+1]);
		}
		}		
}
 rewind(fp); 
    while(!feof(fp))
    {
            fscanf(fp,"%s",test[0]);
    	if (strcmp(x[0],test[0])==0)
    	  {
    	  	printf("\n Compound :  %s ",test[0]);
    	  	fscanf(fp,"%[^\n]",compoundname[0]);
    	  	printf("%s\n",compoundname[0]);
    	  	notfound=1;
    	     break;
		  }
	}
	if(notfound!=1)
	printf("\n   Compound does not found !!!!!\n\n"); 
	 	printf("\n\n                                 -> Thank You <-\n");
	fclose(fp);  	
 }
 void periodic_properties()
 {
 		int o;
	float Ea[118]={72.769,72.814,-48,59.63,-48,26.98,121.776,121.775,-6.8,140.976,140.975,140.975,328.164,-116,52.867,-40,41.762,134.068,72.037,200.410,200.410,348.575,-96,48.383,2.37,18,7.289,50.911,65.21,-50,14.785,63.898,111.65,119.235,-58,29.061,118.935,77.65,194.958,324.536,-96,46.884,5.023,29.6,41.806,88.516,72.10,53,100.96,110.27,54.24,125.862,-68,37.043,107.289,101.059,190.161,295.153,295.154,-77,45.505,13.954,53.795,55,10.539,9.406,12.45,15.63,11.2,13.22,12.67,33.96,32.61,30.10,99,-1.93,23.04,17.18,31,78.76,5.327,103.99,150.908,205.04,222.7,-48,30.880,34.418,90.924,136,233.08,-68,46.86,9.648,33.77,58.633,53.03,30.390,45.85,-48.33,9.93,27.17,-165.24,-97.31,-28.60,33.96,93.91,-223.22,-30.04,151,66.6,35.3,74.9,165.9,5.403};
	float En[118]={2.20,0,0.98,1.57,2.04,2.55,3.04,3.44,3.98,0,0.93,1.31,1.61,1.90,2.19,2.58,3.16,0,0.82,1.00,1.36,1.54,1.63,1.66,1.55,1.83,1.88,1.91,1.90,1.65,1.81,2.01,2.18,2.55,2.96,3.00,0.82,0.95,1.22,1.33,1.6,2.16,1.9,2.2,2.28,2.20,1.93,1.69,1.78,1.96,2.05,2.1,2.66,2.60,0.79,0.89,1.1,1.12,1.13,1.14,1.13,1.17,1.2,1.2,1.1,1.22,1.23,1.24,1.25,1.1,1.27,1.3,1.5,2.36,1.9,2.2,2.20,2.28,2.54,2.00,1.62,2.33,2.02,2.0,2.2,2.2,0.79,0.9,1.1,1.3,1.5,1.38,1.36,1.28,1.13,1.28,1.3,1.3,1.3,1.3,1.3,1.3,1.3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	float At_Ra[118]={56,31,167,112,87,67,56,48,42,38,190,145,118,111,98,88,79,71,243,194,184,176,171,166,161,156,152,149,145,142,136,125,114,103,94,88,265,219,212,206,198,190,183,178,173,169,165,161,156,145,133,123,115,108,298,253,195,185,247,206,205,238,231,233,225,228,226,226,222,222,217,208,200,193,188,185,180,177,174,171,156,154,143,135,127,120,0,195,180,180,175,175,175,175,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	float At_Wt[118]={1.008,4.003,6.941,9.012,10.811,12.011,14.007,15.999,18.998,20.180,22.990,24.305,26.982,28.086,30.974,32.006,35.453,39.948,40.078,44.956,47.867,50.942,51.996,54.938,55.845,58.933,58.693,63.546,65.38,69.723,72.631,74.922,78.971,79.904,83.798,85.468,87.62,88.906,91.224,92.906,95.95,98.907,101.07,102.906,106.42,107.868,112.414,114.818,118.711,121.760,127.6,126.904,131.293,132.905,137.328,138.905,140.116,140.908,144.243,144.913,150.36,151.964,157.25,158.925,162.500,164.930,167.259,168.934,173.055,174.967,178.9,180.948,183.84,186.207,190.23,192.217,195.085,196.967,200.592,204.383,207.2,208.980,208.982,209.987,222.018,223.020,226.025,227.028,232.038,231.036,238.029,237.048,244.064,243.061,247.070,247.070,251.080,254,257.095,258.1,259.101,262,261,262,266,264,269,278,281,280,285,286,289,289,293,294,294};
	printf("\t1)Ionization Energy\n\t2)Eletro Negativity\n\t3)Electron Affinity\n\t4)Atomic radius\n\t5)Atomic Weights\n\t6)Exit\n\n  Enter property number displayed : ");
	scanf("%d",&o);
	switch(o)
	{
		case 1 : 	Ionization_Energy();
		            break;
		case 2 :    trends(En);	 
		            break;
		case 3 :   	trends(Ea);		
		            break;
		case 4 :    trends(At_Ra);
		            break;
	    case 5 :    trends(At_Wt);
		            break;
		case 6 :    printf("\n\n                                 -> Thank You <-\n");
		            break;
		default :    printf("\n  Enter dispalyed choices only\n");														           
	}
 } 
  float check(char x[][7],float m[],int k,int n3)
  {
	    char y[118][3]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nb","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Ti","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","FI","Mc","Lv","Ts","Og"};		
	count=0;
	ip : for(i=0;i<118;i++)
      {
      	count++;
      	if(strcmp(x[k],y[i])==0)
      	{
      		return m[i];
		  }  
	  }
	  if(count==118)
	  {
	  	printf("\n  %d Element does not exist\n\n\t1)Enter Again \n\t2)Continue with remaining elements\n\n  Enter the above displayed choices : ",k+1);
			scanf("%d",&t);
			  if(t==1)
			  {
			  	printf("  Enter element : ");
			  	scanf("%s",x[k]);
			  	count=0;
			  	goto ip;
			  }
			else  if(t==2)
			  {
			  	strcpy(x[k],zero[0]);
			  	return 0;
			  }
			  else
			   {
			   	printf("\n  Enter displayed choices only");
			   	exit(0);
			   }
	  }
  }
  
  void  printorder(char u[][7],float u1[],int n1 )
{
	float temp;
	char temp1[1][7];
  for(i=0;i<n1;i++)
  {
  	for(j=i + 1 ; j<n1 ; j++)
  	{
  		if(u1[i]>u1[j])
  		{
  			temp=u1[i];
  			u1[i]=u1[j];
  			u1[j]=temp;
            strcpy(temp1[0],u[i]);
            strcpy(u[i],u[j]);
            strcpy(u[j],temp1[0]);
		  }
	  }
  }
  for(i=0;i<n1;i++)
  {
  	if(i!=n1 - 1)
  	printf("%s (%f) < ",u[i],u1[i]);
  	else
  		printf("%s (%f) ",u[i],u1[i]);
  }
}
  void Ionization_Energy()
  {
    	float IE1[118]={1312,2372,520.2,899.5,800.6,1086.5,1402.3,1313.9,1681.0,2080,495.8,737.7,577.5,786.5,1011.8,999.6,1251.2,1520.6,418.8,589.8,633.1,658.8,650.9,652.9,717.3,762.5,760.4,737.1,745.5,906.4,572.8,762,947,941,1139,1350,403,549.5,600,640.1,652.1,684.3,702,710.2,719.7,804.4,731,867.8,558.3,708.6,834,869.3,1008.4,1170.4,375.7,502.9,538.1,534.4,527,533.1,540,544.5,547.1,593.4,565.8,573,581,589.3,596.7,603.4,523.5,658.5,761,770,760,840,880,870,890.1,1007.1,589.4,715.6,703,812.1,899.003,1037,380,509.3,499,587,568,597.6,604.5,584.7,578,581,601,608,619,627,635,642,470,580,665,757,740,730,800,960,1020,1155,7077.2,832.2,538.3,663.9,732.9,860.1};
    float IE2[118]={0,5250.5,7298.1,1757.1,2427.1,2352.6,2856,3388.3,3374.2,3952.3,4562,1450.7,1816.7,1577.1,1907,2252,2298,2665.8,3052,1145.4,1235.0,1309.8,1414,1590.6,1590.0,1561.9,1648,1753.0,1957.9,1733.3,1979.3,1537.5,1798,2045,2103,2350.4,2633,1064.2,1180,1270,1380,1560,1470,1620,1740,1870,2070,1631.4,1411.8,1594.9,1790,1845.9,2046.4,2234.3,965.2,1067,1050,1020,1040,1050,1070,1085,1170,1110,1130,1140,1150,1160,1174.8,1340,1440,1500,1700,1260,1600,1600,1791,1980,1810,1971,1450.5,1610,0,0,0,0,979.0,1170,1110,1128,1420,1128,1128,1158,1196,1186,1206,1216,1225,1235,1254,1428,1390,1547,1733,1690,1760,1820,1890,2070,2170,2309,1600,1760,1330,1435.4,1560};
 float IE3[118]={0,0,1815,14848.7,3659.7,4620.5,4578.1,5300.5,6050.4,6122,6910.3,7732.7,2744.8,3231.6,2914.1,3357,3822,3831,4420,4912.4,2388.6,2652.5,2830,2957,3232,3395,3555,3833,2963,3302.1,2735,2973.7,2973.7,3470,3565,3860,4138,1980,2218,2416,2618,2850,2747,2997,3177,3361,3616,2704,2943.0,2440,2698,3180,3099.4,3400,3600,1850.3,1949,2086,2130,2150,2260,2404,1990,2114,2200,2204,2194,2285,2417,2022.3,2250,0,0,2510,0,0,0,0,3300,2878,3081.5,2466,0,0,0,0,0,1900,1978,1814,1900,1997,2084,2132,2026,2152,2267,2334,2363,2470,2643,2228,2300,2378,2484,2570,2830,2900,3030,3080,3160,3226,3370,2650,2850,2161.9,0};
  	printf("\n  Enter how many elements do you need to check : ");
  	scanf("%d",&n);
  	printf("\n");
  	int state[n];
  float values[n],values1[n];
  	char symbol[n][7],symbol1[n][7];
  	char symbol2[n][7];
  	char st1[1][3]={"*"},st2[1][3]={"**"},st3[1][4]={"***"};
  	printf("  User can enter upto 3 ionization states only *\n\n");
  	for(i=0;i<n;i++)
  	{
  		printf("  Enter %d Elements state : ",i+1);
  		scanf("%d",&state[i]);
  		printf("  Enter %d Element as symbol : ",i+1);
  		scanf("%s",symbol[i]);
	  }
     
    ion : for(j=0;j<n;j++)
     {
     	if(state[j]==1)
     	{
     		values[j]=check(symbol,IE1,j,n);
     		strcpy(symbol2[j],symbol[j]);
     		strcat(symbol2[j],st1[0]);
		 }
		else if(state[j]==2)
		 {
		 	values[j]=check(symbol,IE2,j,n);
		 	strcpy(symbol2[j],symbol[j]);
     		strcat(symbol2[j],st2[0]);
		 }
		else if(state[j]==3)
		 {
		 	values[j]=check(symbol,IE3,j,n);
		 	strcpy(symbol2[j],symbol[j]);
     		strcat(symbol2[j],st3[0]);
		 }
		 else
		 {
		 	printf("  Upto 3 Ionization states are acceptable\n  Enter %d Element's State again : ",j+1);
		 	scanf("%d",&state[j]);
		 	goto ion;
		 	
		 }
	 }

			for(i=0;i<n;i++)    // checking if any 0 is there in the arrays
	{
	   	if(strcmp(symbol2[i],zero1[0])!=0 && strcmp(symbol2[i],zero2[0])!=0 && strcmp(symbol2[i],zero3[0])!=0 )
		  {
		  	strcpy(symbol1[n1],symbol2[i]);  // re arranging the array elements without 0
		  	n1++;
		  }
		  if(values[i]!=0)
		  {
		  	values1[n2]=values[i];
		  	n2++;
		  }
	}
	printf("\n  Increasing order : ");
	printorder(symbol1,values1,n1);  
	 	printf("\n\n                                 -> Thank You <-\n");
  }

  void trends(float m[])   
  {
  		printf("\n  Enter Number of Elements do you want to check : ");
        scanf("%d",&n);
        char symbol[n][3];
        printf("\n  Enter Elements as Symbols : ");
             for(i=0;i<n;i++)
             {
             	scanf("%s",symbol[i]);
			 }
			 checking(m,symbol,n);
  }
 
 void checking (float m[],char symbol[][3],int n)
 {
int b;
char At_No[118][3]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nb","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Ti","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","FI","Mc","Lv","Ts","Og"};		
 float values[n],values1[n];
 char symbol1[n][7];
   for(i=0;i<n;i++)
   {   again : count=0;
   	    for(j=0;j<118;j++)
   	      {     count=count+1;
   	    	if(strcmp(At_No[j],symbol[i])==0)
   	        {
   	    		values[i]=m[j];
   	    		break;
		    }
	      }
		if(count==118)
		{
				printf("\n  %d Element does not exist\n\n\t1)Enter Again \n\t2)Continue with remaining elements\n\n  Enter the above displayed choices : ",i+1);
				scanf("%d",&t);
					if(t==1)
				{
					printf("\n  Enter %d element as Symbol : ",i+1);
					scanf("%s",symbol[i]);
					goto again;
	         	}
	         			else if(t==2)
				{
					b=5;
					strcpy(symbol[i],zero[0]);// when user want to countinue with other elements
					values[i]=0;
				}
				else 
			    {
				   	t=3;
				   	goto down;
				}
        }               
 }
 if(b==5)
{
		for(i=0;i<n;i++)    // checking if any 0 is there in the arrays
	{
	   	if(strcmp(symbol[i],zero[0])!=0)
		  {
		  	strcpy(symbol1[n1],symbol[i]);  // re arranging the array elements without 0
		  	n1++;
		  }
		  if(values[i]!=0)
		  {
		  	values1[n2]=values[i];
		  	n2++;
		  }
	}
}
else
{
	for(i=0;i<n;i++)
	{
		strcpy(symbol1[i],symbol[i]);
		values1[i]=values[i];
	}
	n1=n;
}
printf("\n Increasing order : ");
printorder(symbol1,values1,n1); 
down : if(t==3){	printf("\n  You have enetered other than displayed choices start executing again\n");    }
    	printf("\n\n                                 -> Thank You <-\n");
}
 
void iso(char At_No[][3])
{
	int l;
	  int At_num[2],Wt_num[2];
      char Name[118][25]={"Hydrogen","Helium","Lithium","Berrilium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon","Sodium","Magnesium","Alluminium","Silicon","Phosphorus","Sulphur","Chlorines","Argon","Pottasium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickle","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technesium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine","Xenon","Caesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promrthium","Samarium","Europium","Gadolinium","Terbium","Dysoprosium","Holmium","Erbium","Thulium","Ytterbium","Lutetium","Hafnium","Tantalum","Tungesten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon","Framcium","Radium","Actinium","Thorium","Protactium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copermicium","Nihonium","Flerovium","Moscovium","Livermorium","Tennessine","Oganesson"};    	  
	  char x[118][3]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nb","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
	char At_sym[2][3];
	printf("   To comapre two elements weather they are isotopes,isobars,isotones,isodiaphers\n   we need Atomic number/Element symbol and Atomic Weight of two Elements\n");
for(j=0;j<2;j++)
{
	printf("\n   Enter %d Element information\n",j+1);
	printf("\t1)By Atomic Number\n\t2)By Element Symbol\n\n  Enter displayed choices : ");
    scanf("%d",&k);
    if(k==1)
    {
    	printf("   Enter Element %d Atomic Number : ",j+1);
    	scanf("%d",&At_num[j]);
	}
    else if(k==2)
    {
    	printf("   Enter Element %d Symbol : ",j+1);
    	scanf("%s",At_sym[j]);
    	count=0;
    	   sun :for(i=0;i<118;i++)
    	        {    
				    count++;
    	        	if(strcmp(x[i],At_sym[j])==0)
    	        	{
    	        		 At_num[j]=i+1;
    	        		 break;
					}
				}
				if(count==118)
				{
					printf("\n   Element does not exist\n   Enter element again : ");
					scanf("%s",At_sym[j]);
					goto sun;
				}
	}
    else if(k==3)
   	printf("\n\n                                 -> Thank You <-\n");
    else
   {
   	 printf("  Enter displayed choises only\nThank You\n");
   	l=2;
   	 break;
   }
   printf("   Enter Element %d Atmoic Wight : ",j+1);
   scanf("%d",&Wt_num[j]);
   printf("\n");
}
if(l!=2)
{
	if(At_num[0]==At_num[1] && Wt_num[0]!=Wt_num[1])
{
	printf("  These are Isotopes of '%s'\n",Name[At_num[0]-1]);
}
else if(At_num[0]!=At_num[1] && Wt_num[0]==Wt_num[1]) 
{
	printf("  These are isobars");
}
else if(Wt_num[0]-At_num[0]==Wt_num[1]-At_num[1])
{ 
	printf("  These are isotones");
}
else if(Wt_num[0]-2*At_num[0]==Wt_num[1]-2*At_num[1])
{
	printf("  These are isodiaphers");
}
else
{
	    printf("  These are not of any type");
		printf("\n\n                                 -> Thank You <-\n");
}
}
}
