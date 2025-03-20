Habiendo comparado el tiempo que tarde char* y string en comparar si dos textos son identicos en tiempo de ejecucion
puedo concluir que lo mas optimo es usar char*. Esto se debe a la diferencia de velocidad, debido a la practicidad de poder mover el puntero. Estoy conciente de que las implentacion son diferentes, pero aun asi aunque se encuentra una implentacion mas optima para comparar string, este seguira siendo menos optimo que char*. 

Sin embargo, la funcion que se realizo en tiempo de ejecucion es mas rapido que el resto. Esto se debe que a cuando se mide el timpo, esto se hace en tiempo de ejecucion, llamando la funcion dentro, pero como esta ya se realizo, no hace falta hacerlo en ejecucion 

