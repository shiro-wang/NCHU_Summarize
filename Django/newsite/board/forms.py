from django import forms
from . import models
from captcha.fields import CaptchaField

class ProfileForm(forms.ModelForm):
	class Meta:
		model = models.Profile
		fields=['height', 'male', 'website']
	def __init__(self, *args, **kwargs):
		super(ProfileForm, self).__init__(*args, **kwargs)
		self.fields['height'].label = '身哥(cm)'
		self.fields['male'].label = '是男生嗎'
		self.fields['website'].label = '個人網站'

class DateInput(forms.DateInput):
	input_type = 'date'

class DiaryForm(forms.ModelForm):
	class Meta:
		model = models.Diary
		fields = ['budget', 'weight', 'note', 'ddate']
		widgets = {'ddate' : DateInput(),}
	def __init__(self, *args, **kwargs):
		super(DiaryForm, self).__init__(*args, **kwargs)
		self.fields['budget'].label = '今日花費'
		self.fields['weight'].label = '體重'
		self.fields['note'].label = '留言'
		self.fields['ddate'].label = '日期'

class LoginForm(forms.Form):
	# COLORS=[
	# 	['紅', 'Red'],
	# 	['黃', 'Yellow'],
	# 	['綠', 'Green'],
	# 	['藍', 'Blue'],
	# 	['紫', 'Purple'],
	# ]
	user_name = forms.CharField(label='姓名', max_length=10)
	user_password = forms.CharField(label='密碼', widget=forms.PasswordInput())
	# user_color = forms.ChoiceField(label='幸運顏色', choices=COLORS)

class ContactForm(forms.Form):
	CITY=[
		['TP', 'Taipei'],
		['TC' ,'Taichung'],
		['TN', 'Tainan'],
	]
	user_name = forms.CharField(label='姓名', max_length=50, initial='Joan')
	user_city = forms.ChoiceField(label='城市', choices=CITY)
	user_school = forms.BooleanField(label='是否在學', required=False)
	user_email = forms.EmailField(label='Email')
	user_message = forms.CharField(label='意見', widget=forms.Textarea)

class PostForm(forms.ModelForm):
	captcha = CaptchaField()
	class Meta:
		model = models.Post
		fields = ['mood', 'nickname', 'message', 'del_pass']
	def __init__(self, *args, **kwargs):
		super(PostForm, self).__init__(*args, **kwargs)
		self.fields['mood'].label = '心情'
		self.fields['nickname'].label = '暱稱'
		self.fields['message'].label = '留言'
		self.fields['del_pass'].label = '密碼'
		self.fields['captcha'].label = '不是機器人'

class ContactForm2(forms.ModelForm):
	captcha = CaptchaField()
	class Meta:
		model = models.Contact
		fields = [ 'nickname', 'city', 'school', 'email', 'message']
	def __init__(self, *args, **kwargs):
		super(ContactForm2, self).__init__(*args, **kwargs)
		self.fields['nickname'].label = '暱稱'
		self.fields['city'].label = '居住城市'
		self.fields['school'].label = '就讀學校'
		self.fields['email'].label = '電子信箱'
		self.fields['message'].label = '留言'
		self.fields['captcha'].label = '不是機器人'