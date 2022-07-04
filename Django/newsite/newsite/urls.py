from django.contrib import admin
from django.urls import path, re_path, include
from mysite.views import about, listing, disp_detail, homepage, index, engtv, carlist, musictv
import mobilemarket.views as mob
import board.views as board
from django.conf.urls import url

urlpatterns = [
    re_path(r'^admin/', admin.site.urls),
    re_path(r'^$',index, name='home-url'),
    path('about/', about),
    path('about/<int:author_no>/',about, name='about-url'),
    path('about/', about),
    path('list/', listing),
    path('list/<str:sku>/', disp_detail),
    path('list/<int:year>/<int:month>/<int:day>', listing, name = 'list-url'),
    path('<int:tvno>/', index, name = 'tv-url'),
    path('engtv/',engtv),
    path('engtv/<int:tvno>/',engtv, name = 'engtv-url'),
    path('music/',musictv),
    path('music/<int:tvno>/',musictv, name = 'musictv-url'),
    path('carlist/',carlist),
    path('carlist/<int:maker>/',carlist, name = 'carlist-url'),
    path('mobile/',mob.index),
    path('mobile/detail/<int:id>',mob.detail, name='detail-url'),
    path('board/',board.index),
    path('board/browse/',board.browse),
    path('board/write/',board.write),
    path('board/<int:pid>/<str:del_pass>',board.index),
    path('board/post/',board.posting),
    path('board/list/',board.listing),
    path('board/contact/',board.contact),
    path('board/login/', board.login),
    path('board/logout/', board.logout),
    path('board/userinfo/', board.userinfo),
    url(r'^captcha', include('captcha.urls')),
    path('accounts/', include('registration.backends.default.urls')),
]
