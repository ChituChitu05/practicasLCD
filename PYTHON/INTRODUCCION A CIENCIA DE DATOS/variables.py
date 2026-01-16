
#variables
edad= 18 #entero

print(int("5"))
print(float(19))
print(str(19))
bool(0)

a = 15
b = 33
#operadores aritmeticos
print(f"suma:{a+b}")
print(f"resta:{a-b}")
print(f"divicion:{a/b}")
print(f"divicion entera:{a//b}")
print(f"modulo:{a*b}")
print(f"Exponencicion:{a%b}")


#operadores de comparacion 
x = 50
y = 120

print(f"x mayor que y{x>y}")
print(f"x menor que y{x<y}")
print(f"x diferente que y{x!=y}")
print(f"x igual que  y{x==y}")
print(f"x mayor igual que y{x>=y}")
print(f"x menor igual que y{x<=y}")

#operadores logicos 

PI = 3.14159
print ((12>123)and(40<200))
print ((PI<2*PI)or (7<47))
print (not (5==5))

#operadores de asignacion 
x = 80
x += 1 #asignacion de suma
x -= 1 #asigancion de resta
X *= 2 #asignacion multiplicativo
x /= 34 #asignacion division

print (x)

#operadores de pertenencia 

print ('x' in 'banana' )
print (90 in [2,3,4,90])
print ('r' not in 'Oscar')

#operadores de identidad
print('Samuel'is 'Oscar')
print(5 is not 10)


#salidas

print(5)
print("hola Mundo")
print(5>2)

nombre = "Jessica"
edad = 19
print("su nombre es", nombre, "y tiene ", edad, "años")
print(f"su nombre es {nombre} y tiene {edad} años")
print("direccion ip de oscar ", end ='')#end 
print(192, 168, 1, 4, 8, sep='.')#sep