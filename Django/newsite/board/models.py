from django.db import models
from django.contrib import auth

# Create your models here.
class Mood(models.Model):
	status = models.CharField(max_length=10, null=False)

	def __str__(self):
		return self.status

class Post(models.Model):
	mood = models.ForeignKey('Mood', on_delete=models.CASCADE)
	nickname = models.CharField(max_length=10, default="匿名")
	message = models.TextField(null=False)
	del_pass = models.CharField(max_length=10)
	pub_time = models.DateTimeField(auto_now=True)
	enabled = models.BooleanField(default=False)
	born_year = models.PositiveIntegerField(default=1960)

	def __str__(self):
		return self.message

class Contact(models.Model):
	nickname = models.CharField(max_length=20, default="匿名")
	city = models.CharField(max_length=20, default="Taichung")
	school = models.BooleanField(default=False)
	email = models.EmailField()
	message = models.TextField(null=False)

	def __str__(self):
		return self.nickname

class User(models.Model):
	name = models.CharField(max_length=20, null=False)
	email = models.EmailField()
	password = models.CharField(max_length=20, null=False)
	enabled = models.BooleanField(default=False)

	def __str__(self):
		return self.name

class Profile(models.Model):
	user = models.OneToOneField(auth.models.User, on_delete=models.CASCADE)
	height = models.PositiveIntegerField(default=160)
	male = models.BooleanField(default=False)
	website = models.URLField(null=True)
	def __str__(self):
		return self.user.username

class Diary(models.Model):
	user = models.ForeignKey(auth.models.User, on_delete=models.CASCADE)
	budget = models.FloatField(default=0)
	weight = models.FloatField(default=0)
	note = models.TextField()
	ddate = models.DateField()

	def __str__(self):
		"{}({})".format(self.ddate, self.user)