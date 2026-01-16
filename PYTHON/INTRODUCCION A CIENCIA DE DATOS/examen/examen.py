import pandas as pd
import polars as pl
df = pd.read_csv('./dataset_examen.csv')
print(df.head())

# Información del DataFrame
print(df.info())

print("==============VALORES NULOS POR COLUMNA=================")
print(df.isnull())
print(df.isnull().sum())

#Valores no usables
print("==============EDAD NO USABLES=================")
edad_no_usable = df[(df['Age'] < 18) | (df['Age'] > 65) | (df['Age'].isna())]
print(edad_no_usable)


print("==============SALARIO NO USABLES=================")
sal_no_usable = df[(df['Salary'].isna())]
print(sal_no_usable)

print("==============SATISFACTION NO USABLES=================")
sat_no_usable = df[(df['Satisfaction'] < 1) | (df['Satisfaction'] > 5) | (df['Satisfaction'].isna())]
print(sat_no_usable)

print("==============AÑOS DE EXPERIENCIA NO USABLES=================")
exp_no_usable = df[(df['YearsExperience'] < 0) | (df['YearsExperience'].isna())]
print(exp_no_usable)

# Media,moda y mediana
print("==============MEDIDAS DE TENDENCIA CENTRAL=================")
print("==============EDAD=================")
print("Media Edad:", df['Age'].agg(['mean']))
print("Mediana Edad:", df['Age'].agg(['median']))
print("Moda Edad:", df['Age'].agg(['mode']))
'''
cualquier medida de tendencia central marca error por valores no numericos en esta seccion del examen
print("==============SALARIO=================")
print("Media Salario:", df['Salary'].agg(['mean']))
print("Mediana Salario:", df['Salary'].agg(['median']))
print("Moda Salario:", df['Salary'].agg(['mode']))
'''
print("==============SATISFACTION=================")
print("Media Satisfaction:", df['Satisfaction'].agg(['mean']))
print("Mediana Satisfaction:", df['Satisfaction'].agg(['median']))
print("Moda Satisfaction:", df['Satisfaction'].agg(['mode']))  
print("==============AÑOS DE EXPERIENCIA=================")
print("Media Años de Experiencia:", df['YearsExperience'].agg(['mean']))            
print("Mediana Años de Experiencia:", df['YearsExperience'].agg(['median']))
print("Moda Años de Experiencia:", df['YearsExperience'].agg(['mode']))



#limpieza de datos
df_cleaned = df
df_cleaned.loc[df_cleaned['Salary'] == '50O00', 'Salary'] = 50000
df_cleaned = df_cleaned.interpolate(method='linear')
df_cleaned = df_cleaned[(df_cleaned['Age'] >= 18) & (df_cleaned['Age'] <= 65)]
df_cleaned = df_cleaned[(df_cleaned['Satisfaction'] >= 1) & (df_cleaned['Satisfaction'] <= 5)]
df_cleaned = df_cleaned[df_cleaned['YearsExperience'] >= 0]
df_cleaned.loc[df_cleaned['Department'] == ' ', 'Department'] = 'Desconocido'
df_cleaned.loc[df_cleaned['Department'].isna(), 'Department'] = 'Desconocido'


print("==============DATAFRAME LIMPIO=================")
print(df_cleaned)


df2 = pl.read_csv('./dataset_examen.csv')   