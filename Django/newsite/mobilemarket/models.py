# _*_ encoding: utf-8 _*_

from django.db import models

# Create your models here.
class Maker(models.Model):
	name = models.CharField(max_length=10)
	country = models.CharField(max_length=10)
	def __str__(self):
		return self.name

class PModel(models.Model):
	maker = models.ForeignKey(Maker, on_delete=models.CASCADE)
	name = models.CharField(max_length=20)
	url = models.URLField(default='http://mis')
	def __str__(self):
		return self.name

class Product(models.Model):
	pmodel = models.ForeignKey(PModel, on_delete=models.SET_DEFAULT, verbose_name='型號', default=5)
	nickname = models.CharField(max_length=15, default='超值')
	discription = models.TextField(default='無')
	year = models.PositiveIntegerField(default=2018)
	price = models.PositiveIntegerField(default=0)
	def __str__(self):
		return self.nickname
		
class PPhoto(models.Model):
	produce = models.ForeignKey(Product, on_delete=models.CASCADE)
	discription = models.TextField(default='照片')
	url = models.URLField(default='http://mis')
	def __str__(self):
		return self.discription