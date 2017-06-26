X = [A B]
[rX cX] = size(X)
//Reduced Row Echelon Form
Reducida = rref(X)
//Da una matriz con 
Res = zeros(rX,1)
for i=1:1:cX-1
    Res(i)= Reducida(i,cX)
end

RespuestaFinal=Res

