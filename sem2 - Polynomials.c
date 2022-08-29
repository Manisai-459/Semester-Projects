#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct expression{
	int co_eff;
	int power;
	struct expression *next;
}exp;
int i;
void func_free(exp*);
void display(exp*);
exp* insert_in_list(exp*,int,int);
exp* insert_last(exp*,int,int);
exp* add_or_sub(exp*,exp*,int);
exp* multipy(exp*,exp*);
exp* store(exp*,int,int,char*);
exp* char_to_nodes(exp*,char*);
void func_free(exp *ptr1){
   exp *temp;
   while(ptr1){
   	temp = ptr1;
   	ptr1 = ptr1->next;
   	free(temp);
   }
}
void display(exp *h){
	if(!h) printf(" List is empty \n");
	else{
		while(h){
			if(h->power == 0) printf("%d",h->co_eff);
			else    printf("%dx^%d",h->co_eff,h->power);
			if(h->next != NULL){
				  if(h->next->co_eff>=0) 
				        printf("+");
			}
			h = h->next;
		}
	}
}
exp* insert_in_list(exp *ptr,int co,int po){
	exp *real = ptr,*temp;
	temp = (exp*)malloc(sizeof(exp));
	temp->co_eff = co;
	temp->power = po;
	if(!ptr){
		temp->next = NULL;
		return temp;
	}
	else{
		while(ptr->power>po && ptr->next!=NULL)
		    ptr = ptr->next;
		  if(ptr->power == po || co == 0){
 		  	ptr->co_eff += co;  // checking duplicate powers 
		  	free(temp);
		  	return real;       	
		  }
		  else{
		  	if(ptr->next == NULL && ptr->power>po){
		  		ptr->next = temp; 
		  		temp->next = NULL;
		  		return real;
			  }
			else if(ptr == real){
				temp->next = ptr;
				return temp;
			}
			else{
				exp *unreal = real;
			while(unreal->next != ptr)
			  unreal = unreal->next;
			  temp->next =  unreal->next;		
			  unreal->next = temp;
			  return real;
			} 
		  }     
	}
}
exp* insert_last(exp *ptr,int sum1,int po){
	exp* temp = (exp*)malloc(sizeof(exp));
	    temp->co_eff = sum1;
	    temp->power = po;
	    temp->next = NULL;
	    if(ptr == NULL) 
		     return temp;
	    else{
	    	exp *unreal=ptr;
	        while(unreal->next)
	        unreal = unreal->next;
	    	unreal->next = temp;
	    	return ptr;
		}
}
exp* add_or_sub(exp *ptr1,exp *ptr2,int v){
   	    exp *real=ptr2,*temp,*res=NULL;
		int sum;
	    while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->power == ptr2->power){
			if(v == 1)
			sum = ptr2->co_eff + ptr1->co_eff;
		else
		    sum = ptr1->co_eff - ptr2->co_eff;
	    if(sum)
               res = insert_last(res,sum,ptr2->power);
			   ptr1 = ptr1->next;
			   ptr2 = ptr2->next;	
		}				
		else{
			if(ptr1->power>ptr2->power){
				res = insert_last(res,(ptr1->co_eff),ptr1->power);
			    ptr1 = ptr1->next;
			}
			else{
				res = insert_last(res,v*(ptr2->co_eff),ptr2->power);
			    ptr2 = ptr2->next;
			}
		}
	}
	if(ptr1 != NULL){
		while(ptr1){
			res = insert_last(res,(ptr1->co_eff),ptr1->power);	
			ptr1 = ptr1->next;		
		}
	}
	if(ptr2!=NULL){
		while(ptr2){
			res = insert_last(res,v*(ptr2->co_eff),ptr2->power);	
			ptr2 = ptr2->next;	
		}
	}  
	return res;
}
exp* multipy(exp *ptr1,exp *ptr2){
	    exp *temp1=NULL,*temp2=NULL,*temp3=NULL,*real=ptr1;
	    while(ptr2!=NULL){
	    	ptr1 = real;
	    	while(ptr1){
	    		 temp3 = insert_in_list(temp3,(ptr1->co_eff)*(ptr2->co_eff),ptr1->power+ptr2->power);
	    		 ptr1 = ptr1->next;
			}
			ptr2 = ptr2->next;
			if(temp1 == NULL){
				temp1 = temp3;
				temp3 = NULL;
			}
			else if(temp2 == NULL){
				temp2 = temp3;
				temp3 = NULL;
				temp1 = add_or_sub(temp1,temp2,1);
				func_free(temp2);
				temp2 = NULL;
			}
		}
		return temp1;
}
exp* store(exp *ptr,int k,int v,char *p){
	int j,co,po,l,sum = 0;
	if(k == 4) 
	         j = i;
	else
	         j = i+1;
	l = j;
    while(p[j]!='+' && p[j]!='-' && p[j]!='\0')
                 j += 1;  
    while(p[l]!='x' && p[l]!='\0' && l!=j){  // How many digits are there before x encounters ( co- efficient ) ex : 1234x^34
      	co = (p[l]+2)%10;
      	sum = sum*10 + co;
      	l += 1;
	  }
	  if(l == j){
	  	co = sum*v;
	  	po = 0;
	  }else{
	  	co = sum*v;
	  	l = l+2 ;
	  	sum = 0 ;
	  	while(l!=j){
	  		po = (p[l]+2)%10;
	  		sum = sum*10 + po;  // How many digits are there before x encounters ( power ) ex : 34x^12345
	  		l += 1;
		  }
	  	po = sum;
	  }
	  i = j - 1;              // After getting coefficient and power , insert them in Linked list
		ptr = insert_in_list(ptr,co,po);
		return ptr;							
}
exp* char_to_nodes(exp *ptr,char *p){
		for(i=0;i<strlen(p);i++){
		if(i==0){        // 1st term : because 1st char we will not be an operator
			if(p[i] == '-')
	     	ptr = store(ptr,5,-1,p);  
		else
            ptr = store(ptr,4,1,p);			 			   
	    }
		else if(p[i] == '+')    
		    ptr = store(ptr,5,1,p);					
		else if(p[i] == '-')
	    	ptr = store(ptr,5,-1,p);							
	}
		return ptr;
}
int main(){
	exp *exp1=NULL,*exp2=NULL,*exp3=NULL;
	int c,n;
	char *a=NULL,*b=NULL; 
	printf("\t\t\t\t\t\t     ---------------------------------------------------------\n");	
	printf("\t\t\t\t\t\t    | Tool which Adds , Subracts and Multiply two Polynomials |\n");
	printf("\t\t\t\t\t\t     -----------------------         -------------------------\n");
	printf("\t\t\t\t\t\t                            | + - x |\n");
	printf("\t\t\t\t\t\t                             -------\n\n");
	printf("\t\t\t\t\t --------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| <-> Enter expressions in the format of ->  ax^n+bx^n-1+cx^n-2 .....            |\n");
	printf("\t\t\t\t\t| <-> Here ' ^ ' represents power , ' a ' is co efficient and ' n ' is power     |\n");
	printf("\t\t\t\t\t| <-> After completing of Entering Expression click Enter                        |\n");
	printf("\t\t\t\t\t| <-> Don't give spaces it may effect your final Output                          |\n");
	printf("\t\t\t\t\t| <-> Don't Enter any secial Characters                                          |\n");
	printf("\t\t\t\t\t --------------------------------------------------------------------------------\n\n\n");
		do{
		printf("\t 1 . Enter Expressions\n");
		printf("\t 2 . Addition\n");
		printf("\t 3 . Substraction\n");
		printf("\t 4 . Multiply\n");
		printf("\t 5 . Free Expressions\n");
		printf("\t 6 . Display\n");
		printf("\t 7 . Exit\n");
		printf("\t           Enter choise : ");
		scanf("%d",&n);
		if(n == 2)
			c = 1;
		else if(n == 3){
			n = 2;
			c = -1;
		}
		switch(n){
			case 1 :    a = (char*)malloc(50*sizeof(char)); // allocating memory to store exquations
	                    b = (char*)malloc(50*sizeof(char));
	                    exp1 = exp2 = NULL;	
			          	printf("\n\t Enter Equation 1 : ");
			            fflush(stdin);
                    	scanf("%[^\n]s",a);
                        exp1 = char_to_nodes(exp1,a);    // converting string into Lined list
                        printf("\n\t Enter Equation 2 : ");
                        fflush(stdin);
	                    scanf("%[^\n]s",b);      // converting string into Lined list
	                    exp2 = char_to_nodes(exp2,b);
	                    printf("\n\t Equation successfully taken");
	                    break;   
			case 2 :    
			             if(a == NULL && b == NULL)
			                		printf("\n        First Enter Equations !!!!!!!!!\n");
			            else{
			            if(a[0] == '0' && b[0] == '0')
			                printf("\n\t Result   : 0");
						else{
							printf("\n\t Result   : ");
							if(a[0] == '0')
                          	display(exp2);
						    else if(b[0] == '0')
                          	display(exp1); 
						else{
			                exp3 = add_or_sub(exp1,exp2,c);	
                          	display(exp3);
						}			
					}		            	
				}
						 break;	
			case 4 :   if(a == NULL && b == NULL)
			                		printf("\n        First Enter Equations !!!!!!!!!\n");
			            else{
			            if(a[0] == '0' || b[0] == '0')
			            printf("\n\t Result   : 0");
						else{
			            exp3 = multipy(exp1,exp2);
                    	printf("\n\t Result : ");
                          	display(exp3);	
						}
					}
					   break;	 
			case 5 :    free(a);
			            free(b);
			            a = b = NULL;
			            func_free(exp1);
			            func_free(exp2);
						printf("\n\t Equation's  Deleted \n");
						break;							 		     			      
	        case 6 :    
			            if(a == NULL && b == NULL)
			                	printf("\n        First Enter Equations !!!!!!!!!\n");
			            else{
						printf("\n\t Expression 1 : ");					    		
						display(exp1);
						printf("\n\n\t Expression 2 : ");
                        display(exp2);
						}    		
	                    break;
			case 7 :   printf("\n\t\t\t\t\t\t              <----- Thank you ----->                \n");
			           exit(0);
			         break;
			default : printf("\n\t Enter displayed choises only....!!!!!!! \n");			          
		}
		printf("\n\n  ----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	}while(1);			
	return 0;
}
