//declara una matriz cuadrada de coeficientes como A
//Declara el vector columna de constantes o términos independientes como B

//Calcula el determinante (D)
D = det(A)

[r c] = size(A)

for i=1:1:r     //Ciclo para encontrar tantas incógnitas como ecuaciones haya
    Di = A
    //sustituye la columna de la incógnita, con la de los términos independientes
    Di(:,i) = B
    //calcula el valor de la incógnita por regla de Cramer
    x(i) = det(Di)/D
end

//despliega el vector de valores de las incógnitas
disp(x)
