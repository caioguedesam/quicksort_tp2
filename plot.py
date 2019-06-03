import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
data = pd.read_csv('output.csv')

random_time = data[data['Variação do Vetor'] == 'Ale'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Tempo']]
random_comp = data[data['Variação do Vetor'] == 'Ale'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Comparações']]
random_mov = data[data['Variação do Vetor'] == 'Ale'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Movimentações']]

ordc_time = data[data['Variação do Vetor'] == 'OrdC'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Tempo']]
ordc_comp = data[data['Variação do Vetor'] == 'OrdC'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Comparações']]
ordc_mov = data[data['Variação do Vetor'] == 'OrdC'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Movimentações']]

ordd_time = data[data['Variação do Vetor'] == 'OrdD'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Tempo']]
ordd_comp = data[data['Variação do Vetor'] == 'OrdD'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Comparações']]
ordd_mov = data[data['Variação do Vetor'] == 'OrdD'].loc[:,['Variação do Quicksort', 'Tamanho do Vetor', 'Movimentações']]

sizes = [50000,100000,150000,200000,250000,300000,350000,400000,450000,500000]
# Random times
plt.figure(figsize=(12,12))
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QC']['Tempo'], linewidth=3, alpha=0.7,label='QC')
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QM3']['Tempo'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QPE']['Tempo'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QI1']['Tempo'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QI5']['Tempo'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QI10']['Tempo'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, random_time[random_time['Variação do Quicksort'] == 'QNR']['Tempo'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Mediana do Tempo de Ordenação (μs)')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/random_time.png', bbox_inches='tight')

# Random Comparisons
plt.figure(figsize=(12,12))
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QC']['Comparações'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QM3']['Comparações'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QPE']['Comparações'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QI1']['Comparações'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QI5']['Comparações'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QI10']['Comparações'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, random_comp[random_comp['Variação do Quicksort'] == 'QNR']['Comparações'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Média de Comparações')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/random_comp.png', bbox_inches='tight')

# Random Movements
plt.figure(figsize=(12,12))
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QC']['Movimentações'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QM3']['Movimentações'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QPE']['Movimentações'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QI1']['Movimentações'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QI5']['Movimentações'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QI10']['Movimentações'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, random_mov[random_mov['Variação do Quicksort'] == 'QNR']['Movimentações'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Média de Movimentações')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/random_mov.png', bbox_inches='tight')

# Crescent Time
plt.figure(figsize=(12,12))
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QC']['Tempo'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QM3']['Tempo'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QPE']['Tempo'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QI1']['Tempo'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QI5']['Tempo'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QI10']['Tempo'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, ordc_time[ordc_time['Variação do Quicksort'] == 'QNR']['Tempo'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Mediana do Tempo de Ordenação (μs)')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/ordc_time.png', bbox_inches='tight')

# Crescent Comparisons
plt.figure(figsize=(12,12))
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QC']['Comparações'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QM3']['Comparações'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QPE']['Comparações'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QI1']['Comparações'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QI5']['Comparações'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QI10']['Comparações'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, ordc_comp[ordc_comp['Variação do Quicksort'] == 'QNR']['Comparações'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Média de Comparações')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/ordc_comp.png', bbox_inches='tight')

# Crescent Movements
plt.figure(figsize=(12,12))
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QC']['Movimentações'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QM3']['Movimentações'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QPE']['Movimentações'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QI1']['Movimentações'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QI5']['Movimentações'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QI10']['Movimentações'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, ordc_mov[ordc_mov['Variação do Quicksort'] == 'QNR']['Movimentações'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Média de Movimentações')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/ordc_mov.png', bbox_inches='tight')

# Decrescent Time
plt.figure(figsize=(12,12))
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QC']['Tempo'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QM3']['Tempo'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QPE']['Tempo'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QI1']['Tempo'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QI5']['Tempo'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QI10']['Tempo'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, ordd_time[ordd_time['Variação do Quicksort'] == 'QNR']['Tempo'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Mediana do Tempo de Ordenação (μs)')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/ordd_time.png', bbox_inches='tight')

# Decrescent Comparisons
plt.figure(figsize=(12,12))
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QC']['Comparações'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QM3']['Comparações'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QPE']['Comparações'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QI1']['Comparações'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QI5']['Comparações'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QI10']['Comparações'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, ordd_comp[ordd_comp['Variação do Quicksort'] == 'QNR']['Comparações'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Média de Comparações')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/ordd_comp.png', bbox_inches='tight')

# Decrescent Movements
plt.figure(figsize=(12,12))
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QC']['Movimentações'], linewidth=3, alpha=0.7, label='QC')
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QM3']['Movimentações'], linewidth=3, alpha=0.7, label='QM3')
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QPE']['Movimentações'], linewidth=3, alpha=0.7, label='QPE')
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QI1']['Movimentações'], linewidth=3, alpha=0.7, label='QI1')
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QI5']['Movimentações'], linewidth=3, alpha=0.7, label='QI5')
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QI10']['Movimentações'], linewidth=3, alpha=0.7, label='QI10')
plt.plot(sizes, ordd_mov[ordd_mov['Variação do Quicksort'] == 'QNR']['Movimentações'], linewidth=3, alpha=0.7, label='QNR')
plt.ylabel('Média de Movimentações')
plt.xlabel('Tamanho do Vetor')
plt.legend()
plt.savefig('plots/ordd_mov.png', bbox_inches='tight')