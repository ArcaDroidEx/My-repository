import pygame, random

# Videojuego en el que aparecerá una fruta y tenemos que cazarla con
# el ratón. Si pulsamos fuera de la fruta perdemos.

pygame.init()

# Configuración de la pantalla
ANCHO_PANTALLA = 800
ALTO_PANTALLA = 600
pantalla = pygame.display.set_mode((ANCHO_PANTALLA, ALTO_PANTALLA))
pygame.display.set_caption("Shoot the fruit")

# Cargamos la imagen
image = pygame.image.load("./Coding-games-in-Python/images/apple.png")

# Obtener el rectángulo del sprite
image_rect = image.get_rect()

# Actualizamos posición del sprite a una posición al azar
posX = random.randint(image_rect.width, ANCHO_PANTALLA-image_rect.width)
posY = random.randint(image_rect.height, ALTO_PANTALLA-image_rect.height)
posicion = (posX, posY)

# Ajustamos posición inicial, el rectángulo sigue la posición del sprite
# Se usa para verificar los límites y actualizar la posición del sprite 
# junto con la imagen
image_rect.topleft = posicion

# Se usa para gestionar lo rápido se actualiza la pantalla
reloj = pygame.time.Clock()
 
final = False

# -------- Bucle Principal del Programa -----------
while not final:
    # Comprobamos los eventos
    for evento in pygame.event.get(): # El usuario hizo algo
        if evento.type == pygame.QUIT: # Si el usuario pincha sobre cerrar
           final = True
        if evento.type == pygame.MOUSEBUTTONDOWN:
            # Obtener la posición del clic del ratón
            mouse_x, mouse_y = evento.pos

            # Comprobar si el clic fue dentro del sprite
            if image_rect.collidepoint(mouse_x, mouse_y):
                print("¡Clic en el sprite!") 

                # Colocamos el sprite en otra posición al azar
                posX = random.randint(image_rect.width, ANCHO_PANTALLA-image_rect.width)
                posY = random.randint(image_rect.height, ALTO_PANTALLA-image_rect.height)
                posicion = (posX, posY)
                image_rect.topleft = posicion
            else:
                print("Perdiste")
                final = True
 
    # Rellenar la pantalla de blanco
    pantalla.fill((255, 255, 255)) 
 
    # Dibujamos el sprite en la posición
    pantalla.blit(image, image_rect)
     
    #Actualizamos la pantalla
    pygame.display.flip()
 
    # Limita a 20 fotogramas por segundo (frames per second)
    reloj.tick(20)

pygame.quit()
exit()
