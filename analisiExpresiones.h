std::string analisisgeneral(std::string expg){
	char aux[expg.length()];
	char auxelim[expg.length()];
	int cte=0, cte2=0, comillas=0;
	strcpy(aux,expg.c_str());
	while(aux[cte]!=0){
	bool agregare = false;
		(aux[cte]==39)? comillas++ : comillas;
		if(aux[cte]==39 && comillas==1){
			auxelim[cte2]=34;
			cte2++;
			aux[cte] = '[';
		}else if(aux[cte]=='['&&comillas==0){
			auxelim[cte2]=34;
			cte2++;
		}
		if(aux[cte]==39 && comillas==2){
			aux[cte] = ']';
			comillas=0;
			agregare=true;
		}else if(aux[cte]==']'&&comillas==0){
			agregare=true;
		}
		if(aux[cte]!=44){
			auxelim[cte2]=aux[cte];	
			cte2++;
			cte++;
		}else{
		cte++;	
		}
		if(agregare){
			auxelim[cte2]=34;
			cte2++;
		}
	}
	auxelim[cte2]=0;
	std::string volver=auxelim;
	return volver;
}