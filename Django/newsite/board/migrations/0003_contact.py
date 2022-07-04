# Generated by Django 3.2.12 on 2022-05-10 15:20

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('board', '0002_post_born_year'),
    ]

    operations = [
        migrations.CreateModel(
            name='Contact',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('nickname', models.CharField(default='匿名', max_length=20)),
                ('city', models.CharField(default='Taichung', max_length=20)),
                ('school', models.BooleanField(default=False)),
                ('email', models.EmailField(max_length=254)),
                ('message', models.CharField(max_length=100)),
            ],
        ),
    ]