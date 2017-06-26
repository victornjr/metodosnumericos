X = [A B]
[rX cX] = size(X)

//Parte de la eliminación
for p=1:1:rX-1
    pivote = X(p,p)
    for i=p+1:1:rX
        fila = X(i,p)
        X(i,:) = X(i,:) - (X(p,:)/pivote)*fila
    end
end

//Parte de sustitución
//utiliza sustitución hacia atrás
res = zeros(rX,1)
res(rX) = X(rX,cX)/X(rX,cX-1)
for i=rX:-1:1
    c=0
    for j=i+1:rX
        c=c+X(i,j)*res(j)
    end
    res(i) = (X(i,cX)-c)/X(i,i)
end
