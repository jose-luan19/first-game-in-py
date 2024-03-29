import pygame
from math import ceil

## Feito por Magnus, Rudigus e Caius e Luan

# MANUAL #
# Jogador laranja:
# A -> movimenta para trás
# D -> movimenta para frente
# S -> movimenta para baixo
# W -> movimenta para cima
# G -> turbo

# Jogador azul:
# ArrowLeft   -> movimenta para trás
# ArrowRight  -> movimenta para frente
# ArrowDown   -> movimenta para baixo
# ArrowUp     -> movimenta para cima
# L           -> turbo

# F1  -> Reinicia o jogo
# ESC -> Fecha o jogo

placarJ1 = 0
placarJ2 = 0

pygame.init()
vel_img = 0
Acel_img = 0
white = (255,255,255)
darkGreen = (0,100,0)
tela = pygame.display.set_mode((600, 600))
pygame.display.set_caption("UTEBO")
fim = True
TextoMenu = "UTEBO"
FonteMenu = pygame.font.SysFont("monospace", 90, 1)
TextoRegras = "Pressione Espaço para continuar"
FonteRegras = pygame.font.SysFont("monospace", 30, 1)
Menu = FonteMenu.render(TextoMenu, 0, (0, 0, 0))
Regras = FonteRegras.render(TextoRegras, 0, (0, 0, 0))
image = pygame.image.load("boladoluan.png")
while(fim):
    pressed = pygame.key.get_pressed()
    for event in pygame.event.get():
        if(event.type == pygame.QUIT):
            fim = False
        if(pressed[pygame.K_SPACE]):
            vel_img+=0.5
    Acel_img += vel_img
    tela.fill(darkGreen)
    tela.blit(image, (150+Acel_img, 350 - Acel_img))
    tela.blit(Menu, (150, 0))
    tela.blit(Regras, (25, 200))
    if(350-Acel_img == 0):
        fim = False
    pygame.display.flip()
pygame.quit()
def main():
    global placarJ1
    global placarJ2
    digitos = 1 # Auxilia no placar
    auxPlacarJ1 = placarJ1
    while (auxPlacarJ1 >= 10):
        auxPlacarJ1 = auxPlacarJ1 / 10
        digitos += 1
    print(digitos)
    pygame.init()

    infoTela = pygame.display.Info()
    largura = infoTela.current_w
    altura = infoTela.current_h
    screen = pygame.display.set_mode((largura, altura), pygame.FULLSCREEN)
    fontePlacar = pygame.font.SysFont("monospace", 90, 1)
    espacos = ""
    for i in range(digitos):
        espacos += " "
    textoPlacar = str(placarJ1) + espacos + str(placarJ2)
    placar = fontePlacar.render(textoPlacar, 0, (0, 0, 0))
    done = True # Varíável que controla o fluxo do jogo
    is_blue = True
    t = largura//2 # X do centro do círculo
    k = altura//2 # Y do centro do círculo
    tj = 20 # Tamanho do Jogador
    x = [largura - largura//15 - tj, largura//15] ## coordenada na linha x dos jogadores
    y = [altura / 2 - tj//2 , altura / 2 - tj//2] ## coordenada na linha y dos jogadores
    vel1 = 4 ##velocidade do jogador 1
    vel2 = 4 ##velocidade do jogador 2
    multEnergia = 1.5 ## a velocidade aumenta em 50%
    r = 14 ##raio da bola
    energiaJ1 = 100 ##stamina
    energiaJ2 = 100 ##stamina
    custoEnergia = 1
    clock = pygame.time.Clock()
    corrida1 = False
    corrida2 = False
    while done:
        for event in pygame.event.get():
            if (event.type == pygame.KEYDOWN and event.key == pygame.K_F1):
                placarJ1 = 0
                placarJ2 = 0
                main()
            if (event.type == pygame.QUIT):
                done = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                is_blue = not is_blue
            if (event.type == pygame.KEYDOWN and event.key == pygame.K_l and energiaJ1 >= custoEnergia):
                vel1 = vel1 * multEnergia
                corrida1 = True
            if (event.type == pygame.KEYUP and event.key == pygame.K_l and corrida1):
                vel1 = vel1 / multEnergia
                corrida1 = False
            if (event.type == pygame.KEYDOWN and event.key == pygame.K_g and energiaJ2 >= custoEnergia):
                vel2 = vel2 * multEnergia
                corrida2 = True
            if (event.type == pygame.KEYUP and event.key == pygame.K_g and corrida2):
                vel2 = vel2 / multEnergia
                corrida2 = False
        if(energiaJ1 < custoEnergia and corrida1):
            vel1 = vel1 / multEnergia
            corrida1 = False
        if(energiaJ2 < custoEnergia and corrida2):
            vel2 = vel2 / multEnergia
            corrida2 = False
        # Bola enconsta no lado esquerdo
        if(t - r < 0):
            if(not(t - r < 0 and k > altura//4 and k < 3 * altura//4)):
                t = r + 1
        # Bola encosta no lado direito
        if(t + r > largura):
            if(not(t + r > largura and k > altura//4 and k < 3 * altura // 4)):
                t = largura - (r * 2)
        # Bola encosta no teto
        if(k - r < 0):
            k = r+1
        # Bola encosta no chão
        if(k + r > altura):
            k = altura - (r * 2)
        
        distX = abs(x[0] - x[1])
        distY = abs(y[0] - y[1])
        if(x[0] < t):
            distTX = (t - r) - (x[0] + tj)
        else:
            distTX = x[0] - (t + r)
        if(x[1] < t):
            distTX1 = (t - r) - (x[1] + tj)
        else:
           distTX1 = x[1] - (t + r)
        if(y[0] > k):
            distTY = y[0] - (k + r)
        else:
            distTY = (k - r) - (y[0] + tj) 
        if(y[1] > k):
            distTY1 = y[1] - (k + r)
        else:
            distTY1 = (k - r) - (y[1] + tj)
        pressed = pygame.key.get_pressed()
        # Energia / Stamina
        if (pressed[pygame.K_l] and energiaJ1 >= custoEnergia):
            energiaJ1 -= custoEnergia
        if(pressed[pygame.K_g] and energiaJ2 >= custoEnergia):
            energiaJ2 -= custoEnergia
        # Movimento dos Jogadores (J1 e J2)
        if pressed[pygame.K_ESCAPE]:
            done = False
        if pressed[pygame.K_UP]:
            if(not(distX <= tj and abs(y[0] - vel1 - y[1]) <= tj and y[0] > y[1]) and (not(y[0] <= 0))):
                y[0] -= vel1
        if pressed[pygame.K_DOWN]:
            if(not(distX <= tj and abs(y[0] + vel1 - y[1]) <= tj and y[0] < y[1]) and (not(y[0]+tj >= altura))):
                y[0] += vel1
        if pressed[pygame.K_LEFT]:
            if(not(abs(x[0] - vel1 - x[1]) <= tj and distY <= tj and x[0] > x[1]) and (not(x[0] <= 0))):
                x[0] -= vel1
        if pressed[pygame.K_RIGHT]:
            if(not(abs(x[0] + vel1 - x[1]) <= tj and distY <= tj and x[0] < x[1]) and (not(x[0] + tj >= largura))):
                x[0] += vel1
        if pressed[pygame.K_w]:
            if(not(distX <= tj and abs(y[0] - (y[1] - vel2)) <= tj and y[1] > y[0]) and (not(y[1] <= 0))):
                y[1] -= vel2
        if pressed[pygame.K_s]:
            if(not(distX <= tj and abs(y[0] - (y[1] + vel2)) <= tj and y[1] < y[0]) and (not(y[1]+tj >= altura))):
                y[1] += vel2
        if pressed[pygame.K_a]:
            if(not(abs(x[0] - (x[1] - vel2)) <= tj and distY <= tj and x[1] > x[0]) and (not(x[1] <= 0))):
                x[1] -= vel2
        if pressed[pygame.K_d]:
            if(not(abs(x[0] - (x[1] + vel2)) <= tj and distY <= tj and x[1] < x[0]) and (not(x[1]+tj >= largura))):
                x[1] += vel2
        # Movimento da Bola
        velBola1 = ceil(vel1)
        velBola2 = ceil(vel2)
        # Movimento da Bola pra Direita (J1)
        if(distTX<=0 and x[0]<t and distTY <= -4):
            t += velBola1
        # Movimento da Bola pra Esquerda (J1)
        if(distTX<=0 and x[0]>t and distTY <= -(velBola1)):
            t -= velBola1
        # Movimento da Bola pra Direita (J2)
        if(distTX1<=0 and x[1]<t and distTY1 <= -(velBola2)):
            t += velBola2
        # Movimento da Bola pra Esquerda (J2)
        if(distTX1<=0 and x[1]>t and distTY1 <= -(velBola2)):
            t -= velBola2
        # Movimento da Bola pra Baixo (J1)
        if(distTY<=0 and y[0]<k and distTX <= -(velBola1)):
            k += velBola1
        # Movimento da Bola pra Cima (J1)
        if(distTY<=0 and y[0]>k and distTX <= -(velBola1)):
            k -= velBola1
        # Movimento da Bola pra Baixo (J2)
        if(distTY1 <= 0 and y[1]<k and distTX1 <= -(velBola2)):
            k += velBola2
        # Movimento da Bola pra Cima (J2)
        if(distTY1 <= 0 and y[1]>k and distTX1 <= -(velBola2)):
            k -= velBola2
        # Gol do J2
        if(t + r > largura and k > altura//4 and k < 3 * altura // 4):
            print("GOL DO CAIO") # colocar isso no display, ou apagar
            placarJ1 += 1
            return main()
        # Gol do J1
        if(t - r < 0 and k > altura//4 and k < 3 * altura // 4):
            print("GOL DO MAGNUS") # colocar isso no display, ou apagar
            placarJ2 += 1
            return main()
        # Ferramenta de Debug
        if pressed[pygame.K_o]:
            print("jogador 1: ", distTX, distTY, "jogador 2: ", distTX1, distTY1 , t , k)
        screen.fill((0, 0, 0))
        if is_blue:
            blue = (0, 0, 255)
            black = (0,0,0)
            orange = (255, 100, 0)
            white = (255,255,255)
            darkGreen = (0,100,0)
            cinza = (100, 100, 100)
            yellow = (255, 255, 0)
        # Gramado
        pygame.draw.rect(screen,darkGreen,pygame.Rect(0,0,largura,altura))
        # Círcunferência Central
        pygame.draw.circle(screen,white,[largura//2,altura//2],70,1)
        # Linha Central
        pygame.draw.rect(screen,white,pygame.Rect(largura//2,0,1,altura))
        # Área Esquerda
        pygame.draw.rect(screen,white,pygame.Rect(0,altura//4,170,1))
        pygame.draw.rect(screen,white,pygame.Rect(0,3 * altura//4,170,1))
        pygame.draw.rect(screen,white,pygame.Rect(170,altura//4,1,altura//2))
        # Área Direita
        pygame.draw.rect(screen,white,pygame.Rect(largura - 170,altura//4,170,1))
        pygame.draw.rect(screen,white,pygame.Rect(largura - 170,3 * altura//4,170,1))
        pygame.draw.rect(screen,white,pygame.Rect(largura - 170,altura//4,1,altura//2))
        # Jogadores de Futebol
        pygame.draw.rect(screen, blue, pygame.Rect(x[0], y[0], tj, tj))
        pygame.draw.rect(screen, orange, pygame.Rect(x[1], y[1], tj, tj))
        # Bola
        pygame.draw.circle(screen, cinza, [t,k], r)
        pygame.draw.circle(screen, cinza, [t,k], r)
        # Barra de Energia Direita
        pygame.draw.rect(screen, yellow, pygame.Rect(largura - 50 - energiaJ1 * 2, 50, energiaJ1 * 2, 50))
        # Barra de Energia Esquerda
        pygame.draw.rect(screen, yellow, pygame.Rect(50, 50, energiaJ2 * 2, 50))
        # Placar
        screen.blit(placar, (largura//2 - 80 * digitos, 60))
        pygame.display.flip()
        # Energia / Stamina
        if(energiaJ1 < 100):
            energiaJ1 += custoEnergia / 7
        else:
            energiaJ1 = 100
        if(energiaJ2 < 100):
            energiaJ2 += custoEnergia / 7
        else:
            energiaJ2 = 100
        clock.tick(60)

main()
pygame.quit()
