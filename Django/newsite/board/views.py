from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from board import models
from . import forms
from django.contrib.sessions.models import Session
from django.contrib import messages, auth
from django.contrib.auth import authenticate
from django.contrib.auth.decorators import login_required

# Create your views here.
def index(request, pid=None, del_pass=None):
	# if request.session.test_cookie_worked():
	# 	request.session.delete_test_cookie()
	# 	alert_message = 'cookie supported'
	# else:
	# 	alert_message = 'cookie not supported'
	# request.session.set_test_cookie()
	if request.user.is_authenticated:
		username = request.user.username
		useremail = request.user.email
		# usercolor = request.session['usercolor']
	try:
		user = auth.models.User.objects.get(username=username)
		diaries = models.Diary.objects.filter(user=user).order_by('-ddate')
	except:
		pass
	return(render(request, "board/index.html",locals()))

def browse(request):
	posts = models.Post.objects.filter(enabled=True).order_by('-pub_time')[:30]
	
	return(render(request, "board/browse.html",locals()))

def write(request):
	try:
		user_id = request.GET["user_id"]
		user_pass = request.GET["user_pass"]
		user_post = request.GET["user_post"]
		user_mood= request.GET["mood"]
		user_byear = request.GET["byear"]
	except:
		user_id = None
		alert_message = "欄位皆必填"
	years = range(1960,2022)
	mood = models.Mood.objects.all()
	if user_id != None:
		input_mood = models.Mood.objects.get(status=user_mood)
		input_post = models.Post.objects.create(mood=input_mood, nickname=user_id, del_pass=user_pass, message=user_post)
		input_post.save()
		alert_message = "儲存成功"
	
	return(render(request, "board/write.html",locals()))
@login_required(login_url='/board/login/')
def posting(request):
	# if 'username' in request.session:
	# 	username = request.session['username']
	# years = range(1960,2022)
	# mood = models.Mood.objects.all()
	# try:
	# 	user_id = request.POST["user_id"]
	# 	user_pass = request.POST["user_pass"]
	# 	user_post = request.POST["user_post"]
	# 	user_mood= request.POST["mood"]
	# 	user_byear = request.POST["byear"]
	# except:
	# 	user_id = None
	# 	alert_message = "欄位皆必填"
	# if user_id != None:
	# 	input_mood = models.Mood.objects.get(status=user_mood)
	# 	input_post = models.Post.objects.create(mood=input_mood, nickname=user_id, del_pass=user_pass, message=user_post, born_year=user_byear)
	# 	input_post.save()
	# 	alert_message = "儲存成功"

	if request.user.is_authenticated:
		username = request.user.username
		useremail = request.user.email
	messages.get_messages(request)

	if request.method == 'POST':
		user = auth.models.User.objects.get(username = username)
		diary = models.Diary(user = user)
		post_form = forms.DiaryForm(request.POST, instance=diary)
		if post_form.is_valid():
			#alert_message = "儲存成功"
			messages.add_message(request, messages.INFO, '日記已儲存')
			post_form.save()
			return HttpResponseRedirect('/board')
		else:
			messages.add_message(request, messages.WARNING, "欄位皆必填")
	else:
		post_form = forms.DiaryForm()
		messages.add_message(request, messages.WARNING, "欄位皆必填")

	return(render(request, "board/posting.html",locals()))

def listing(request):
	posts = models.Post.objects.filter(enabled=True).order_by('-pub_time')[:30]
	
	return(render(request, "board/listing.html",locals()))

def contact(request):
	if request.method == 'POST':
		form = forms.ContactForm2(request.POST) 		#填錯不會全不見
		if form.is_valid():
			# user_name = form.cleaned_data['user_name']
			# user_city = form.cleaned_data['user_city']
			# user_school = form.cleaned_data['user_school']
			# user_email = form.cleaned_data['user_email']
			# user_message = form.cleaned_data['user_message']
			alert_message="感謝來信"
			form.save()
		else:
			alert_message="資料不正確"
	else:
		form = forms.ContactForm2()
		username = request.session['username']
	return(render(request, "board/contact.html", locals()))

def login(request):
	if request.method == 'POST':
		login_form = forms.LoginForm(request.POST)
		if login_form.is_valid():
			username = request.POST['user_name'].strip()
			password = request.POST['user_password']
			user = authenticate(username=username, password=password)
			if user is not None:
				if user.is_active:
					auth.login(request, user)
					messages.add_message(request, messages.SUCCESS, '登入成功')
					return HttpResponseRedirect('/board')
				else:
					messages.add_message(request, messages.WARNING, '帳號未啟用')
			else:
				messages.add_message(request, messages.WARNING, '登入失敗')
			# try:
			# 	user = models.User.objects.get(name=username)
			# 	if user.password == password:
			# 		request.session['username'] = user.name
			# 		request.session['email'] = user.email
			# 		messages.add_message(request, messages.SUCCESS, '登入成功')
			# 		return HttpResponseRedirect('/board')
			# 	else:
			# 		messages.add_message(request, messages.WARNING, '密碼錯誤')
			# except:
			# 	messages.add_message(request, messages.WARNING, '找不到使用者')
			# 	# alert_message = '找不到使用者'
		else:
			messages.add_message(request, messages.INFO, '檢查欄位')
			# alert_message = '請檢查輸入欄位'
	else:
		login_form = forms.LoginForm()
	# try:
	# 	if username:
	# 		request.session['username'] = username
	# 	if usercolor:
	# 		request.session['usercolor'] = usercolor
	# except:
	# 	pass

	return render(request, "board/login.html", locals())


def logout(request):
	# request.session['username'] = None
	# request.session['usercolor'] = None
	# if 'username' in request.session:
	# 	Session.objects.all().delete()
	auth.logout(request)
	messages.add_message(request, messages.INFO, '登出成功')
	return HttpResponseRedirect('/board')

@login_required(login_url='/board/login/')
def userinfo(request):
	# if 'username' in request.session:
	# 	username = request.session['username']
	# 	useremail = request.session['email']
	# else:
	# 	return HttpResponseRedirect('/board/login/')
	if request.user.is_authenticated:
		username = request.user.username
		try:
			user = auth.models.User.objects.get(username=username)
			userinfo = models.Profile.objects.get(user=user)
		except:
			userinfo = models.Profile(user=user)
	if request.method == "POST":
		profile_form = forms.ProfileForm(request.POST, instance=userinfo)
		if profile_form.is_valid():
			messages.add_message(request, messages.INFO, '個人資料已儲存')
			profile_form.save()
			return HttpResponseRedirect('/board/userinfo/')
		else:
			messages.add_message(request, messages.INFO, '檢查欄位')
	else:
		profile_form = forms.ProfileForm()

	return render(request, "board/userinfo.html", locals())