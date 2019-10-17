import matplotlib.pyplot as plt

combinaciones = []

factor = 33
productos = []

for i in range(1, 31):
    combinaciones.append((i*factor, (31-i)*factor))

for i in combinaciones:
    # print('Combinación:', i[0], i[1], '\nProducto:\n', i[0]*i[1])
    productos.append(i[0]*i[1])

# for i in range(0, len(combinaciones)):
    # print('Combinación:', combinaciones[i][0], combinaciones[i][1], end='')
    # print('\nProducto: ', productos[i], '\n')
    # print('./filter ./tests/test_03.png output.png', combinaciones[i][0], combinaciones[i][1])

tiempos1 = [
0.000000,
0.000000,
0.000000,
0.000000,
0.015625,
0.015625,
0.015625,
0.000000,
0.015625,
0.015625,
0.031250,
0.015625,
0.015625,
0.015625,
0.031250,
0.015625,
0.015625,
0.015625,
0.031250,
0.015625,
0.015625,
0.031250,
0.015625,
0.015625,
0.015625,
0.015625,
0.015625,
0.000000,
0.015625,
0.000000

]

print(len(tiempos1), len(combinaciones))

plt.plot(productos, tiempos1, 'ro')
# plt.axis([0, 6, 0, 20])
plt.show()
